import serial
import time

PORT = "COM3"
BAUD = 115200
DURATION = 60  # seconds

ser = serial.Serial(PORT, BAUD, timeout=0.1)

print("Waiting for header...")

header = None

# wait for REAL CSV header
while True:
    raw = ser.readline().decode(errors="ignore").strip()
    if raw.startswith("timestamp"):
        header = raw
        break

print("HEADER FOUND:", header)

lines = [header]  # include header in saved file

print("Recording 1 minute...")

start = time.time()

while time.time() - start < DURATION:
    raw = ser.readline().decode(errors="ignore").strip()
    if raw:
        lines.append(raw)

ser.close()

with open("dataset_raw_60s.csv", "w") as f:
    for ln in lines:
        f.write(ln + "\n")

print("Saved", len(lines), "rows to dataset_raw_60s.csv")   