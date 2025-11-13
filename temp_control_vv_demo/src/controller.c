
#include "controller.h"

/* BUG: incorrect hysteresis logic - heater turns ON when temp is ABOVE setpoint */

int control_heater(float temp, float setpoint) {
    float h = 0.5f;
    if (temp > setpoint - h) {
        return 1; /* WRONG: should turn on when temp < setpoint - h */
    }
    if (temp < setpoint + h) {
        return 0;
    }
    return 0;
}
