
CC=gcc
CFLAGS= -std=c17 -pedantic -Wall -Wextra
CPPFLAGS= 
CXX=g++
CXXFLAGS= -std=c++20 -Wall -Wextra -pedantic
LDFLAGS=

BUILD_DIR=build

.PHONY: all clean

all: $(BUILD_DIR)/main | $(BUILD_DIR)

$(BUILD_DIR)/main: $(BUILD_DIR)/main.o | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(LDFLAGS) $(BUILD_DIR)/main.o -o $(BUILD_DIR)/main

$(BUILD_DIR)/main.o: | $(BUILD_DIR)
	$(CC) $(CPPFLAGS) -c src/main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
