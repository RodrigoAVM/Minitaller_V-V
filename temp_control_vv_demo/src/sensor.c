
#include "sensor.h"
#include <stdlib.h>
#include <time.h>

/* BUG: uses uninitialized 'noise' variable and memory allocation not freed */

float read_temperature(void) {
    float base = 25.0f;
    float noise; /* uninitialized - BUG */
    noise = noise * 0.1f; /* using uninitialized value */
    /* intentional allocation (leak) to show valgrind) */
    char *tmp = (char*)malloc(16);
    if (tmp) tmp[0] = '\0'; /* not freed */
    return base + noise;
}
