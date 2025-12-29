#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X tof;

// Calibration values for this sensor / string
bool tofCalibrated = false;
uint16_t d_air  = 0;   // no hand
uint16_t d_touch = 0;  // finger in playing position

// For smoothing & hysteresis
float engagementSmooth = 0.0f;
const float ENG_ALPHA = 0.2f;  // smoothing factor
bool stringActive = false;
bool stringActivePrev = false;
unsigned long lastFlipMs = 0;
const unsigned long ACTIVE_HOLD_MS = 60; // ms to confirm state changes

uint16_t readDistance() {
  uint16_t d = tof.readRangeSingleMillimeters();
  if (tof.timeoutOccurred()) {
    Serial.println("ToF timeout");
    return 0xFFFF; // invalid
  }
  return d;
}

// Normalize distance -> engagement (0..1)
float computeEngagement(uint16_t d) {
  if (!tofCalibrated) return 0.0f;

  // Safety: avoid divide-by-zero
  if (d_air == d_touch) return 0.0f;

  // Clamp d within calibration range
  if (d > d_air)  d = d_air;
  if (d < d_touch) d = d_touch;

  float num   = (float)d_air - (float)d;
  float denom = (float)d_air - (float)d_touch;
  float e = num / denom;  // 0..1 ideally

  if (e < 0.0f) e = 0.0f;
  if (e > 1.0f) e = 1.0f;
  return e;
}

void handleToFCalibration(uint16_t d) {
  if (Serial.available()) {
    char c = Serial.read();

    if (c == 'a') {
      d_air = d;
      Serial.print("Set d_air (no hand) = ");
      Serial.println(d_air);
    }

    if (c == 't') {
      d_touch = d;
      Serial.print("Set d_touch (finger on string) = ");
      Serial.println(d_touch);
    }

    if (d_air > 0 && d_touch > 0 && d_air != d_touch) {
      tofCalibrated = true;
      Serial.println("ToF calibration DONE: using d_air & d_touch.");
    }
  }
}

// Update stringActive using engagement + hysteresis
void updateStringState(float engagement) {
  // choose threshold; you can adjust this later
  const float ON_THRESHOLD  = 0.6f;
  const float OFF_THRESHOLD = 0.4f; // hysteresis: off a bit lower

  bool wantedActive = stringActive;

  if (!stringActive && engagement > ON_THRESHOLD) {
    wantedActive = true;
  } else if (stringActive && engagement < OFF_THRESHOLD) {
    wantedActive = false;
  }

  unsigned long now = millis();
  if (wantedActive != stringActivePrev) {
    // candidate change started
    stringActivePrev = wantedActive;
    lastFlipMs = now;
  }

  if ((now - lastFlipMs) > ACTIVE_HOLD_MS && stringActive != stringActivePrev) {
    stringActive = stringActivePrev;

    // Event: string state changed
    Serial.print("STRING STATE -> ");
    Serial.println(stringActive ? "ACTIVE" : "INACTIVE");
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin(21, 22);  // adjust if needed

  if (!tof.init()) {
    Serial.println("VL53L0X init failed");
    while (1) delay(100);
  }
  tof.setTimeout(500);
  Serial.println("VL53L0X OK");

  Serial.println("ToF one-string mode:");
  Serial.println(" - Put nothing in front of sensor, press 'a' for d_air.");
  Serial.println(" - Put finger in playing position, press 't' for d_touch.");
}

void loop() {
  uint16_t d = readDistance();
  if (d == 0xFFFF) {
    delay(200);
    return;
  }

  // Handle calibration commands
  handleToFCalibration(d);

  float e = 0.0f;
  if (tofCalibrated) {
    // Engagement calc + smoothing
    float eRaw = computeEngagement(d);
    engagementSmooth = ENG_ALPHA * eRaw + (1.0f - ENG_ALPHA) * engagementSmooth;
    e = engagementSmooth;

    updateStringState(e);
  }

  // Debug print
  Serial.print("d = ");
  Serial.print(d);
  Serial.print(" mm");

  if (tofCalibrated) {
    Serial.print(" | engagement = ");
    Serial.print(e, 2);
    Serial.print(" | pressed string = ");
    Serial.print(stringActive ? "1" : "0");
  } else {
    Serial.print(" | NOT CALIBRATED (press 'a' then 't')");
  }

  Serial.println();
  delay(100);
}

// MIDI CONNECTION FOR STRING PRESS

/* void onStringStateChange(bool active) {
  // TODO later: send MIDI, BLE, whatever
  Serial.print("STRING STATE -> ");
  Serial.println(active ? "ACTIVE" : "INACTIVE");
}

...

if ((now - lastFlipMs) > ACTIVE_HOLD_MS && stringActive != stringActivePrev) {
  stringActive = stringActivePrev;
  onStringStateChange(stringActive);
}*/