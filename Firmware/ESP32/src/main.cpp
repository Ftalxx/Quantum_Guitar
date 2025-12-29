#include "strumming/StrumIMU.h"
// #include "fretting/FretIMU.h" later

StrumIMU strum;

void setup() {
    Serial.begin(115200);
    strum.begin();
}

void loop() {
    if (strum.update()) {
        if (strum.direction() > 0) {
            Serial.println("STRUM UP");
        } else {
            Serial.println("STRUM DOWN");
        }
    }

    // left-hand logic here
}
