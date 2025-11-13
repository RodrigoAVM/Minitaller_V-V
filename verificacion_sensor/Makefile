CC=gcc
CFLAGS=-Wall -Wextra -std=c99

all: test_bad test_fixed

test_bad: src/sensor_bad.c test/test_harness.c
	$(CC) $(CFLAGS) -o test_bad src/sensor_bad.c test/test_harness.c

test_fixed: src/sensor.c test/test_harness.c
	$(CC) $(CFLAGS) -o test_fixed src/sensor.c test/test_harness.c

clean:
	rm -f test_bad test_fixed
