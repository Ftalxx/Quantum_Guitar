#include "LeftHandIMU.h"

/* ===== Initialize I2C ===== */
void LeftHandIMU::begin() {
    Wire.begin(SDA_PIN, SCL_PIN);
    delay(100);
}

/* ===== Select mux channel ===== */
void LeftHandIMU::selectMux(uint8_t channel) {
    Wire.beginTransmission(MUX_ADDR);
    Wire.write(1 << channel);
    Wire.endTransmission();
}

/* ===== Wake up MPU-6050 ===== */
bool LeftHandIMU::initIMU(IMU_ID imu) {
    selectMux(imu);

    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x6B);  // PWR_MGMT_1
    Wire.write(0x00);  // wake up
    return (Wire.endTransmission() == 0);
}

/* ===== Read raw accel + gyro ===== */
bool LeftHandIMU::readRaw(
    IMU_ID imu,
    int16_t &ax, int16_t &ay, int16_t &az,
    int16_t &gx, int16_t &gy, int16_t &gz
) {
    selectMux(imu);

    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x3B); // ACCEL_XOUT_H
    if (Wire.endTransmission(false) != 0) return false;

    Wire.requestFrom(MPU_ADDR, 14);
    if (Wire.available() < 14) return false;

    ax = (Wire.read() << 8) | Wire.read();
    ay = (Wire.read() << 8) | Wire.read();
    az = (Wire.read() << 8) | Wire.read();
    Wire.read(); Wire.read(); // temp ignored
    gx = (Wire.read() << 8) | Wire.read();
    gy = (Wire.read() << 8) | Wire.read();
    gz = (Wire.read() << 8) | Wire.read();

    return true;
}

/* ===== Pretty name helper ===== */
const char* LeftHandIMU::imuName(IMU_ID imu) {
    switch (imu) {
        case WRIST_LEFT:  return "WRIST_LEFT";
        case WRIST_RIGHT: return "WRIST_RIGHT";
        case THUMB:       return "THUMB";
        case INDEX:       return "INDEX";
        case PALM_BACK:   return "PALM_BACK";
        case MIDDLE:      return "MIDDLE";
        case RING:        return "RING";
        case PINKY:       return "PINKY";
        default:          return "UNKNOWN";
    }
}
