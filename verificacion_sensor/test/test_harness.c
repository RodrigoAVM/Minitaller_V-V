#include <stdio.h>

void sensor_init(void);
float sensor_get_average(void);

int main(void) {
    sensor_init();
    float avg = sensor_get_average();
    if (avg != 0.0f)
        printf("FAIL: test_sensor_init - Expected 0.00, Got %.2f\n", avg);
    else
        printf("PASS: test_sensor_init\n");

    printf("Tests completed.\n");
    return 0;
}
