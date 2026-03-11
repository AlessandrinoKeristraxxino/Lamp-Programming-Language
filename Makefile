CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRC_DIR = src
SRCS = $(SRC_DIR)/lexer.cpp $(SRC_DIR)/parser.cpp
TARGET = lamp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET) $(FILE)

.PHONY: all clean run