import serial
import time
import csv

# -----------------------------
# SETTINGS
# -----------------------------
PORT = "COM3"       # set your ESP32 port
BAUD = 115200
OUTPUT_FILE = "strum_training.csv"

# Each entry: (label, duration_in_seconds)
TRAINING_PHASES = [
    ("slow", 5),
    ("fast", 5),
    ("up_only", 5),
    ("sharp", 5),
    ("soft", 5),
    ("pause", 3),
    ("normal", 5)
]

# -----------------------------
# MAIN LOGGER
# -----------------------------
def run_logger():
    ser = serial.Serial(PORT, BAUD, timeout=1)
    print("Connecting to ESP32...")
    time.sleep(2)

    # Wait for header from ESP32
    header_line = ""
    while True:
        if ser.in_waiting:
            line = ser.readline().decode(errors="ignore").strip()
            if "timestamp" in line:
                header_line = line
                break

    print("Header received:", header_line)

    # Prepare CSV file
    headers = header_line.split(",") + ["label"]
    csv_file = open(OUTPUT_FILE, "w", newline="")
    writer = csv.writer(csv_file)
    writer.writerow(headers)

    print("\n=== STARTING TRAINING ROUTINE ===")
    time.sleep(1)

    # -------------------------
    # TRAINING PHASE LOOP
    # -------------------------
    for label, duration in TRAINING_PHASES:
        print(f"\n>>> Get ready to: {label} strums for {duration} seconds")
        time.sleep(2)
        print(f"GO: {label}")

        start_time = time.time()
        while time.time() - start_time < duration:
            if ser.in_waiting:
                raw = ser.readline().decode(errors="ignore").strip()
                if raw and raw[0].isdigit():
                    row = raw.split(",") + [label]
                    writer.writerow(row)

        print(f"Completed: {label}")

    print("\n=== TRAINING COMPLETE ===")
    csv_file.close()
    ser.close()


if __name__ == "__main__":
    run_logger()
