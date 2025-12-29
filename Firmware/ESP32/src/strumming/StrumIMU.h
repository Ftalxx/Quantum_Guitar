#ifndef STRUM_IMU_H
#define STRUM_IMU_H

#include <MPU6050.h>

class StrumIMU {
public:
    StrumIMU();

    void begin();
    bool update(); // true if strum detected
    int direction(); // +1 up, -1 down
    float velocity(); // optional later

private:
    MPU6050 mpu;

    float gyroZ;
    unsigned long lastStrumTime;
    int lastDirection;

    const float STRUM_THRESHOLD = 80.0;
    const unsigned long DEBOUNCE_US = 120000;
};

#endif
