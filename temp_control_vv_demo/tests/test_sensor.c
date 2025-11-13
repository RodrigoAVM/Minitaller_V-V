
#include <stdio.h>
#include <assert.h>
#include "sensor.h"

int main(void) {
    float t = read_temperature();
    /* Expect nominal around 25 +/- 10 (with proper implementation) */
    if (t < -50.0f || t > 200.0f) {
        printf("[FAIL] sensor value out of realistic range: %f\n", t);
        return 1;
    }
    printf("[PASS] test_sensor: value=%f\n", t);
    return 0;
}
