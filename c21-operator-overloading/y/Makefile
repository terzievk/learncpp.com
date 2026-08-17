CXX := g++
CXXFLAGS := -std=c++26 -O2 -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror

TARGET := f
SRCS := Board.cpp Direction.cpp main.cpp Tile.cpp UserInput.cpp Point.cpp
OBJS := $(SRCS:.cpp=.o)
HEADERS := Board.h Direction.h Random.h Tile.h UserInput.h Point.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
