CC = g++
CFLAGS = -Wall -std=c++11

SRC_DIR = src
BUILD_DIR = build
TARGET = myprog

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.hpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
