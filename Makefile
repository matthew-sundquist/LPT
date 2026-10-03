
CC=gcc
CFLAGS= -std=c17 -pedantic -Wall -Wextra
CPPFLAGS= 
CXX=g++
CXXFLAGS= -std=c++20 -Wall -Wextra -pedantic
LDFLAGS=
LDLIBS= 

BUILD_DIR=build
SRC_DIR=src

TARGET = $(BUILD_DIR)/main

LIB = $(BUILD_DIR)/liblpt.a

C_SRCS = $(shell find $(SRC_DIR) -type f -name '*.c')
CPP_SRCS = $(shell find $(SRC_DIR) -type f -name '*.cpp')

LIB_SRC_C = $(filter-out main.c,$(C_SRCS))
LIB_SRC_CPP = $(CPP_SRCS)

LIB_OBJ = $(LIB_SRC:.c=.o)
LIB_OBJ_CPP = $(LIB_SRC:.cpp=.o)
MAIN_OBJ = $(BUILD_DIR)/main.o

.PHONY: all clean

all: $(TARGET) | $(BUILD_DIR)

$(TARGET): $(MAIN_OBJ) $(LIB) | $(BUILD_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(LIB): $(LIB_OBJ) $(LIB_OBJ_CPP) | $(BUILD_DIR)
	ar rcs $@ $^

$(LIB_OBJ): $(LIB_SRC_C) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIB_OBJ_CPP): $(LIB_SRC_CPP) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

$(MAIN_OBJ): src/main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
