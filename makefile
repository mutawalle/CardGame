CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

SRC_DIR = src
BUILD_DIR = build

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRCS:%.cpp=%.o))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o main

clean:
	rm -rf $(BUILD_DIR)/* main
