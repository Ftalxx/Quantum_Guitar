import serial
import time
import numpy as np
import pandas as pd

PORT = "COM3"
BAUD = 115200

CALIBRATION_DURATION = 4   # seconds

def collect_calibration_data():
    ser = serial.Serial(PORT, BAUD, timeout=1)
    time.sleep(2)

    print("\nWaiting for header...")

    header = None
    while True:
        if ser.in_waiting:
            line = ser.readline().decode(errors="ignore").strip()
            if "timestamp" in line:
                header = line.split(",")
                break

    print("Header:", header)

    print("\nStrum in beat for 4 seconds to calibrate...")
    time.sleep(1)
    print("GO.")

    start = time.time()
    rows = []

    while time.time() - start < CALIBRATION_DURATION:
        if ser.in_waiting:
            raw = ser.readline().decode(errors="ignore").strip()
            if raw and raw[0].isdigit():
                parts = raw.split(",")
                if len(parts) == len(header):
                    rows.append(parts)

    ser.close()

    df = pd.DataFrame(rows, columns=header)

    # Convert numeric columns
    for col in df.columns:
        df[col] = pd.to_numeric(df[col], errors="coerce")

    return df


def compute_axis_features(df):
    # Exclude timestamp column
    axes = df.columns[1:]

    results = {}

    for col in axes:
        series = df[col].dropna()

        # Min/max
        col_min = series.min()
        col_max = series.max()

        # Zero crossings: sign change events
        signs = np.sign(series)
        zero_crossings = np.sum(signs[:-1] * signs[1:] < 0)

        # Range
        amplitude = col_max - col_min

        results[col] = {
            "min": float(col_min),
            "max": float(col_max),
            "amplitude": float(amplitude),
            "zero_crossings": int(zero_crossings)
        }

    return results


def determine_primary_axis(results):
    # Pick axis with biggest amplitude *and* consistent zero crossings
    best_axis = None
    best_score = -1

    for axis, stats in results.items():
        # Weight amplitude higher, but still want oscillation
        score = stats["amplitude"] + stats["zero_crossings"] * 50

        if score > best_score:
            best_score = score
            best_axis = axis

    return best_axis


def run_strum_calibration():
    df = collect_calibration_data()
    results = compute_axis_features(df)
    primary = determine_primary_axis(results)

    print("\n=== STRUM CALIBRATION RESULTS ===")
    print("Primary strum axis:", primary)
    print("Stats for primary axis:", results[primary])

    return {
        "primary_axis": primary,
        **results[primary]
    }


if __name__ == "__main__":
    cal = run_strum_calibration()
    print("\nCalibration object:", cal)
