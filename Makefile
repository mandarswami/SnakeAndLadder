CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = project
SRCS = main.cpp board.cpp player.cpp snakeLadder.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rvf $(OBJS) $(TARGET)

.PHONY: all clean