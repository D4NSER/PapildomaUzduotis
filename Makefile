# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra

# Define the source files
SRCS = main.cpp funkcijos.cpp

# Define the header files
HEADERS = funkcijos.h mylib.h

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Define the executable name
TARGET = my_program

# Default rule to build the project
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile the source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean the build directory
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
