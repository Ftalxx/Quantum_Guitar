#ifndef LEFT_HAND_IMU_H
#define LEFT_HAND_IMU_H

#include <Arduino.h>
#include <Wire.h>

/* ===== ESP32 I2C ===== */
#define SDA_PIN 21
#define SCL_PIN 22

/* ===== MUX + IMU ===== */
#define MUX_ADDR 0x70
#define MPU_ADDR 0x68

/* ===== Semantic mapping (LOCKED) ===== */
enum IMU_ID {
    WRIST_LEFT  = 0,  // SD0
    WRIST_RIGHT = 1,  // SD1
    THUMB       = 2,  // SD2
    INDEX       = 3,  // SD3
    PALM_BACK   = 4,  // SD4
    MIDDLE      = 5,  // SD5
    RING        = 6,  // SD6
    PINKY       = 7   // SD7
};

class LeftHandIMU {
public:
    void begin();
    bool initIMU(IMU_ID imu);

    bool readRaw(
        IMU_ID imu,
        int16_t &ax, int16_t &ay, int16_t &az,
        int16_t &gx, int16_t &gy, int16_t &gz
    );

    const char* imuName(IMU_ID imu);

private:
    void selectMux(uint8_t channel);
};

#endif
