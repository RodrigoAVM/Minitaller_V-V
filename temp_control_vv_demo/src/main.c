
#include <stdio.h>
#include "sensor.h"
#include "controller.h"

int main(void) {
    float setpoint = 25.0f;
    for (int i = 0; i < 10; i++) {
        float t = read_temperature();
        int heater = control_heater(t, setpoint);
        printf("Temp: %.2f C | Heater: %s\n", t, heater == 1 ? "ON" : (heater == 0 ? "OFF" : "NO_CHANGE"));
    }
    return 0;
}
