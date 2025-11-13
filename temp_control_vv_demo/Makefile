
CC = gcc
CFLAGS = -I./src -Wall -Wextra -std=c99 -g
SRC = src/sensor.c src/controller.c src/main.c
OBJ = $(SRC:.c=.o)
TARGET = temp_control

TEST_SENSOR = tests/test_sensor.c src/sensor.c src/controller.c -I./src
TEST_CONTROLLER = tests/test_controller.c src/controller.c -I./src

.PHONY: all clean test static valgrind coverage run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

test_sensor:
	$(CC) $(CFLAGS) -o test_sensor $(TEST_SENSOR)
	./test_sensor

test_controller:
	$(CC) $(CFLAGS) -o test_controller $(TEST_CONTROLLER)
	./test_controller

test: test_sensor test_controller

static:
	cppcheck --enable=all --inconclusive --std=c99 --language=c --suppress=missingIncludeSystem src tests

valgrind_test: test_sensor
	valgrind --leak-check=full ./test_sensor || true

coverage:
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage -o test_cov $(TEST_SENSOR)
	./test_cov
	gcov src/sensor.c || true

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) test_sensor test_controller test_cov *.gcda *.gcno *.gcov
