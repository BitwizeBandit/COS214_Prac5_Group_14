CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra
DEBUGFLAGS := -g -O0
 
SRC_DIR := src
BUILD_DIR := build
TARGET := campusguard
 
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
 
.PHONY: all debug clean
 
all: $(TARGET)
 
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
 
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
 
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
 
# Rebuilds with debug symbols and no optimisation, for use with gdb.
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: clean $(TARGET)
 
clean:
	rm -rf $(BUILD_DIR) $(TARGET)