#include <Wire.h>
#include <MPU6050.h>

#define SDA_PIN 21
#define SCL_PIN 22

MPU6050 mpu;

// IMU State
struct IMUState {
  float pitch = 0;
  float roll = 0;
  float ax, ay, az;
  float pitchOffset = 0;
  float rollOffset = 0;
  bool isCalibrated = false;
};

IMUState armIMU;

// Fret mapping state
struct FretMap {
  float rollFret1 = 0;
  float rollFret20 = 0;
  float degreesPerFret = 4.0; // default
  bool rangeSet = false;
  int currentFret = 1;
  float minActiveRoll;
  float maxActiveRoll;
  float activeBuffer = 2.0; // degrees tolerance
  bool inPlayZone = false; 
  float fretTolerance = 2.0;  // degrees buffer to allow natural arm jitter
};

FretMap fretData;

// Complementary filter
float alpha = 0.97;
unsigned long lastTime;

// Function declarations
void updateIMU();
void handleCalibrationInput();
void computeFretPosition();
void printSensorDebug();

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  mpu.initialize();

  if (mpu.testConnection()) Serial.println("✓ MPU6050 connected");
  else Serial.println("✗ ERROR: MPU6050 not detected");

  delay(1000);
  lastTime = micros();
}

void loop() {
  updateIMU();
  handleCalibrationInput();
  computeFretPosition();
  printSensorDebug(); // Throttled output
}

void updateIMU() {
  int16_t axRaw, ayRaw, azRaw, gxRaw, gyRaw, gzRaw;
  mpu.getAcceleration(&axRaw, &ayRaw, &azRaw);
  mpu.getRotation(&gxRaw, &gyRaw, &gzRaw);

  // Convert to g and deg/sec
  float ax = axRaw / 16384.0;
  float ay = ayRaw / 16384.0;
  float az = azRaw / 16384.0;
  float gx = gxRaw / 131.0;
  float gy = gyRaw / 131.0;

  unsigned long now = micros();
  float dt = (now - lastTime) / 1000000.0;
  lastTime = now;

  float accPitch = atan2f(-ax, sqrtf(ay * ay + az * az)) * 180.0 / PI;
  float accRoll = atan2f(ay, az) * 180.0 / PI;

  armIMU.pitch = alpha * (armIMU.pitch + gx * dt) + (1 - alpha) * accPitch;
  armIMU.roll  = alpha * (armIMU.roll + gy * dt) + (1 - alpha) * accRoll;
}

void handleCalibrationInput() {
  if (!Serial.available()) return;
  char c = Serial.read();

  if (c == '1') { // Record fret 1
    fretData.rollFret1 = armIMU.roll;
    Serial.printf("📍 Fret 1 calibrated: %.2f°\n", fretData.rollFret1);
  }

  if (c == '2') { // Record fret 20
    fretData.rollFret20 = armIMU.roll;
    fretData.degreesPerFret = (fretData.rollFret20 - fretData.rollFret1) / 19.0;
    fretData.rangeSet = true;

    if (fretData.rollFret1 > fretData.rollFret20) {
    // RollFret1 is higher (less negative)
    fretData.maxActiveRoll = fretData.rollFret1 - fretData.activeBuffer;
    fretData.minActiveRoll = fretData.rollFret20 + fretData.activeBuffer;
    }else {
    // If reversed order (unlikely but safe)
    fretData.maxActiveRoll = fretData.rollFret20 - fretData.activeBuffer;
    fretData.minActiveRoll = fretData.rollFret1 + fretData.activeBuffer;
    }
    
    Serial.printf("Active roll zone: %.2f° to %.2f°\n",
      fretData.minActiveRoll, fretData.maxActiveRoll);

    Serial.printf("📍 Fret 20 calibrated: %.2f°\n", fretData.rollFret20);
    Serial.printf("🎸 Degrees per fret: %.2f°\n", fretData.degreesPerFret);
  }
}

void computeFretPosition() {
  if (!fretData.rangeSet) return;

  // Check whether you're actively in guitar-playing orientation
  fretData.inPlayZone = (
    armIMU.roll >= fretData.minActiveRoll &&
    armIMU.roll <= fretData.maxActiveRoll
  );

  if (!fretData.inPlayZone) {
    // Option 1: freeze at last valid fret
    // Option 2: mark as inactive
    // I'm going with freeze (makes musical sense)
    return;
  }

  float delta = armIMU.roll - fretData.rollFret1;
  
  // Calculate ideal fret
  int rawFret = round(delta / fretData.degreesPerFret) + 1;
  rawFret = constrain(rawFret, 1, 20);

  // Only update if movement clearly passes tolerance threshold
  float rawFretAngle = fretData.rollFret1 + (rawFret - 1) * fretData.degreesPerFret;
  float diff = abs(armIMU.roll - rawFretAngle);

  if (diff > fretData.fretTolerance) {
      fretData.currentFret = rawFret; // intentional motion confirmed
  }
}  
// else → do nothing, keep currentFret (freeze effect)


void printSensorDebug() {
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint < 120) return;
  lastPrint = millis();

  Serial.printf("Zone %.2f° to %.2f° | Now: %.2f°\n", 
              fretData.minActiveRoll, 
              fretData.maxActiveRoll,
              armIMU.roll);

/*
  Serial.printf("Pitch: %.2f° | Roll: %.2f° | ", armIMU.pitch, armIMU.roll);
  if (fretData.rangeSet) {
      if (fretData.inPlayZone)
        Serial.printf("🎯 Fret: %d (ACTIVE)\n", fretData.currentFret);
      else
        Serial.println("🚫 Out of play zone (fret frozen)");
  }
  else {
      Serial.println("⚠️ Frets not calibrated");
  }

  */
  delay(500);
}

// !!!!!! THERES STRINGS WITHOUT HEAT TUBING