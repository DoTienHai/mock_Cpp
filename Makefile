CC = g++
CFLAGS = -Wall -std=c++17
SRC_DIR = .
BUILD_DIR = build
TARGET = main

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*/*.cpp)
# Header files
INCS = $(wildcard $(SRC_DIR)/*.h $(SRC_DIR)/*/*/*.h)
# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Include directories
INC_DIRS = -I$(SRC_DIR) -I$(SRC_DIR)/Controller/inc -I$(SRC_DIR)/Model/inc -I$(SRC_DIR)/View/inc

# Run
run: build
	./$(TARGET)

# Compile
build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: clean
