#include <Wire.h>
#include "VL53L0X.h"
#include <Arduino.h>

// Adjust these if your I2C scan says otherwise:
#define MUX_IMU_ADDR  0x71   // IMU TCA9548A
#define MUX_TOF_ADDR  0x70   // ToF TCA9548A

#define BICEP_ADDR    0x69   // Bicep MPU6050 on main bus (AD0 = HIGH)
#define MUX_IMU_MPU   0x69   // Muxed MPU6050s also AD0 = HIGH

// IMU mux channels
#define CH_IMU_2  2   // sensor 2
#define CH_IMU_3  3   // sensor 3

VL53L0X tof;

// --------- helpers ---------
void selectMux(uint8_t muxAddr, uint8_t channel) {
  Wire.beginTransmission(muxAddr);
  Wire.write(1 << channel);
  Wire.endTransmission();
}

int readWHO(uint8_t addr) {
  Wire.beginTransmission(addr);
  Wire.write(0x75);        // WHO_AM_I for MPU6050
  Wire.endTransmission(false);
  Wire.requestFrom(addr, (uint8_t)1);
  if (!Wire.available()) return -1;
  return Wire.read();
}

bool readMPU(uint8_t addr,
             int16_t &ax, int16_t &ay, int16_t &az,
             int16_t &gx, int16_t &gy, int16_t &gz)
{
  Wire.beginTransmission(addr);
  Wire.write(0x3B);        // ACCEL_XOUT_H
  if (Wire.endTransmission(false) != 0) return false;

  Wire.requestFrom(addr, (uint8_t)14);
  if (Wire.available() < 14) return false;

  uint8_t d[14];
  for (int i = 0; i < 14; i++) d[i] = Wire.read();

  ax = (d[0] << 8) | d[1];
  ay = (d[2] << 8) | d[3];
  az = (d[4] << 8) | d[5];

  gx = (d[8] << 8) | d[9];
  gy = (d[10] << 8) | d[11];
  gz = (d[12] << 8) | d[13];

  return true;
}

void wakeMPU(uint8_t addr) {
  Wire.beginTransmission(addr);
  Wire.write(0x6B);    // PWR_MGMT_1
  Wire.write(0x00);    // wake
  Wire.endTransmission();
}

// --------- setup ---------
void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);   // ESP32 pins; change if needed
  delay(300);

  Serial.println("\n=== MULTI SENSOR TEST (bicep + IMU2 + IMU3 + ToFs ch2-7) ===");

  // Wake bicep (direct)
  wakeMPU(BICEP_ADDR);

  // Wake muxed IMUs on ch2 & ch3
  selectMux(MUX_IMU_ADDR, CH_IMU_2);
  wakeMPU(MUX_IMU_MPU);

  selectMux(MUX_IMU_ADDR, CH_IMU_3);
  wakeMPU(MUX_IMU_MPU);

  // Turn off IMU mux routes for now
  selectMux(MUX_IMU_ADDR, 0x00);
}

// --------- loop ---------
void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  int id;

  // ---- BICEP (direct, 0x69) ----
  Serial.println("\n[BICEP MPU]");
  id = readWHO(BICEP_ADDR);
  if (id == 0x68) {
    Serial.println("WHO_AM_I = 0x68 (OK)");
    if (readMPU(BICEP_ADDR, ax, ay, az, gx, gy, gz)) {
      Serial.printf("ACC: %d %d %d | GYRO: %d %d %d\n", ax, ay, az, gx, gy, gz);
    } else {
      Serial.println("Failed reading bicep data");
    }
  } else {
    Serial.print("Bicep NOT FOUND, WHO_AM_I = 0x");
    Serial.println(id, HEX);
  }

  // ---- IMU on mux channel 2 ----
  Serial.println("\n[IMU CH2 via MUX]");
  selectMux(MUX_IMU_ADDR, CH_IMU_2);
  delay(5);
  id = readWHO(MUX_IMU_MPU);
  if (id == 0x68) {
    Serial.println("WHO_AM_I = 0x68 (OK)");
    if (readMPU(MUX_IMU_MPU, ax, ay, az, gx, gy, gz)) {
      Serial.printf("ACC: %d %d %d | GYRO: %d %d %d\n", ax, ay, az, gx, gy, gz);
    } else {
      Serial.println("Failed reading IMU ch2 data");
    }
  } else {
    Serial.print("IMU ch2 NOT FOUND, WHO_AM_I = 0x");
    Serial.println(id, HEX);
  }

  // ---- IMU on mux channel 3 ----
  Serial.println("\n[IMU CH3 via MUX]");
  selectMux(MUX_IMU_ADDR, CH_IMU_3);
  delay(5);
  id = readWHO(MUX_IMU_MPU);
  if (id == 0x68) {
    Serial.println("WHO_AM_I = 0x68 (OK)");
    if (readMPU(MUX_IMU_MPU, ax, ay, az, gx, gy, gz)) {
      Serial.printf("ACC: %d %d %d | GYRO: %d %d %d\n", ax, ay, az, gx, gy, gz);
    } else {
      Serial.println("Failed reading IMU ch3 data");
    }
  } else {
    Serial.print("IMU ch3 NOT FOUND, WHO_AM_I = 0x");
    Serial.println(id, HEX);
  }

  // Turn off IMU mux again
  selectMux(MUX_IMU_ADDR, 0x00);

  // ---- TOF SENSORS via ToF mux, channels 2–7 ----
  Serial.println("\n[TOF SENSORS ch2-7]");
  for (uint8_t ch = 2; ch <= 7; ch++) {
    Serial.printf("TOF ch%d: ", ch);
    selectMux(MUX_TOF_ADDR, ch);
    delay(5);

    tof.init();
    tof.setTimeout(50);
    uint16_t dist = tof.readRangeSingleMillimeters();
    if (!tof.timeoutOccurred()) {
      Serial.printf("%u mm\n", dist);
    } else {
      Serial.println("NO RESPONSE");
    }
  }

  // Turn off ToF mux too
  selectMux(MUX_TOF_ADDR, 0x00);

  Serial.println("\n--- FRAME END ---");
  delay(500);
}
