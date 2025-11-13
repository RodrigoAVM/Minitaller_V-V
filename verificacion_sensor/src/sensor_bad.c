#include <stdio.h>
#define FILTER_SIZE 10

static float readings[FILTER_SIZE];
static int index, count;

void sensor_init(void) {
    for (int i = 0; i < FILTER_SIZE; i++) readings[i] = 0.0f;
    index = 0;
    // BUG: faltó inicializar count = 0
}

float sensor_get_average(void) {
    float sum = 0.0f;
    for (int i = 0; i < FILTER_SIZE; i++) sum += readings[i];
    return sum / FILTER_SIZE;
}
