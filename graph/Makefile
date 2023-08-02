CC = g++

# C++ compiler options
CXXFLAGS = -Wall -O2

# Linker options
LDFLAGS = 

# Directory of source files
SRC_DIR = ./src

# Directory of object files
OBJ_DIR = ./obj

# Name of execution file
TARGET = main

# Source files
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))

OBJS = $(SRCS:.cpp=.o)

OBJECTS = $(patsubst %.o, $(OBJ_DIR)/%.o,$(OBJS))
DEPS = $(OBJECTS:.o=.d)

all: main

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -MD $(LDFLAGS)

$(TARGET) : $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

.PHONY: clean all
clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)

-include $(DEPS)