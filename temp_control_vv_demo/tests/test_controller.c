
#include <stdio.h>
#include <assert.h>
#include "controller.h"

int main(void) {
    float set = 25.0f;
    /* Should be ON when temp is well below setpoint */
    int on = control_heater(23.0f, set); /* expect 1 */
    if (on != 1) { printf("[FAIL] controller should be ON at 23.0\n"); return 1; }
    /* Should be OFF when temp is well above setpoint */
    int off = control_heater(27.0f, set); /* expect 0 */
    if (off != 0) { printf("[FAIL] controller should be OFF at 27.0\n"); return 1; }
    printf("[PASS] test_controller\n");
    return 0;
}
