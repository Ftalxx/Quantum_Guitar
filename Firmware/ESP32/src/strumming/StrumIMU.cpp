#include "StrumIMU.h"
#include <Wire.h>
#include <Arduino.h>

StrumIMU::StrumIMU()
  : gyroZ(0),
    lastStrumTime(0),
    lastDirection(0) {}

void StrumIMU::begin() {
    Wire.begin();
    mpu.initialize();

    mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_500);
    mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_4);
}

bool StrumIMU::update() {
    int16_t gx, gy, gz;
    mpu.getRotation(&gx, &gy, &gz);

    gyroZ = gz / 65.5;
    unsigned long now = micros();

    if (abs(gyroZ) > STRUM_THRESHOLD &&
        (now - lastStrumTime) > DEBOUNCE_US) {

        lastStrumTime = now;
        lastDirection = (gyroZ > 0) ? 1 : -1;
        return true;
    }

    return false;
}

int StrumIMU::direction() {
    return lastDirection;
}

float StrumIMU::velocity() {
    return abs(gyroZ);
}
