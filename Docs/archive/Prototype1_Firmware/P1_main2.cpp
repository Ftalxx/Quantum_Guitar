#include <Wire.h>
#include <Adafruit_VL53L0X.h>

// ------------------ CONFIG ------------------
#define MUX_ADDR 0x70
#define FIRST_CHANNEL 2
#define LAST_CHANNEL 7
#define NUM_SENSORS 6

const char* stringNames[NUM_SENSORS] = {"E", "A", "D", "G", "B", "e"};

const uint8_t STABILITY_READS = 4;      // Hysteresis per sensor
const uint8_t DUAL_NOTE_TOLERANCE = 15; // mm tolerance for barre
const uint16_t MAX_VALID_DIST = 400;    // mm, ignore if beyond
const uint16_t INVALID_DIST = 9999;
const uint16_t ACTIVATION_DIFF = 15;    // how much closer means “pressed”
const uint8_t OPEN_READS_REQUIRED = 20; // calibration stabilizing
const unsigned long HOLD_TIME_MS = 200; // ignore super fast taps

Adafruit_VL53L0X tof;

uint16_t distances[NUM_SENSORS];
uint16_t baseline[NUM_SENSORS];
bool calibrated = false;

// Stability tracking
uint8_t stabilityCount[NUM_SENSORS];
bool activeState[NUM_SENSORS];   // final per-string activation
unsigned long lastActiveTime[NUM_SENSORS];

// ------------------ HELPER FUNCS ------------------

void setMuxChannel(uint8_t channel) {
  Wire.beginTransmission(MUX_ADDR);
  Wire.write(1 << channel);
  Wire.endTransmission();
}

void calibrateSensors() {
  static uint8_t readCount = 0;

  for (int i = 0; i < NUM_SENSORS; i++) baseline[i] += distances[i];
  readCount++;

  if (readCount >= OPEN_READS_REQUIRED) {
    for (int i = 0; i < NUM_SENSORS; i++) baseline[i] /= readCount;
    calibrated = true;
    Serial.println("🎯 Calibration complete!");
  }
}

// ------------------ SETUP ------------------

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  Serial.println("\nInitializing sensors...");

  for (int ch = FIRST_CHANNEL; ch <= LAST_CHANNEL; ch++) {
    setMuxChannel(ch);
    delay(50);
    if (!tof.begin()) Serial.printf("❌ Sensor CH %d FAILED\n", ch);
    else Serial.printf("✔ Sensor CH %d OK\n", ch);
  }

  Serial.println("Hold hand in OPEN POSITION...");
}

// ------------------ LOOP ------------------

void loop() {

  // ----------- Read sensors -----------
  for (int ch = FIRST_CHANNEL; ch <= LAST_CHANNEL; ch++) {
    setMuxChannel(ch);
    delay(10);

    VL53L0X_RangingMeasurementData_t measure;
    tof.rangingTest(&measure, false);

    int i = ch - FIRST_CHANNEL;

    if (measure.RangeStatus != 4 && measure.RangeMilliMeter < MAX_VALID_DIST) {
      distances[i] = measure.RangeMilliMeter;
    } else distances[i] = INVALID_DIST;
  }

  // ----------- Calibration Phase -----------
  if (!calibrated) {
    calibrateSensors();
    if (!calibrated) {
      Serial.print(".");
      delay(50);
      return;
    }
  }

  // ----------- Detect Activation -----------
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (distances[i] + ACTIVATION_DIFF < baseline[i]) {
      stabilityCount[i]++;
      if (stabilityCount[i] >= STABILITY_READS) {
        if (!activeState[i]) lastActiveTime[i] = millis();
        activeState[i] = true;
      }
    } else {
      stabilityCount[i] = 0;
      activeState[i] = false;
    }
  }

  // ----------- Collect active strings -----------
  int activeStrings[NUM_SENSORS];
  int activeCount = 0;

  for (int i = 0; i < NUM_SENSORS; i++) {
    if (activeState[i] && (millis() - lastActiveTime[i] > HOLD_TIME_MS)) {
      activeStrings[activeCount++] = i;
    }
  }

  // ----------- Detect barre -----------
  bool barre = false;
  if (activeCount >= 4) {
    uint16_t ref = distances[activeStrings[0]];
    int similar = 1;
    for (int i = 1; i < activeCount; i++) {
      if (abs((int)distances[activeStrings[i]] - (int)ref) < DUAL_NOTE_TOLERANCE) similar++;
    }
    if (similar >= 4) barre = true;
  }

  // ----------- Output -----------
  if (activeCount == 0) {
    Serial.println("🎸 Open / No strings pressed");
  } else if (barre) {
    Serial.print("🎸 BARRE detected on: ");
    for (int i = 0; i < activeCount; i++)
      Serial.print(String(stringNames[activeStrings[i]]) + " ");
    Serial.println();
  } else {
    Serial.print("🎸 Strings pressed: ");
    for (int i = 0; i < activeCount; i++)
      Serial.print(String(stringNames[activeStrings[i]]) + " ");
    Serial.println();
  }

  delay(50);
}
