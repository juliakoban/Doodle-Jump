# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Directories containing header files
INC_DIRS = -Iinclude

# Linker flags
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS = main.cpp Entity.cpp EntityState.cpp Player.cpp Collider.cpp CollisionHandler.cpp Camera.cpp Game.cpp Score.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Main target
app: $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Rule to compile .cpp files to .o files
%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

# Run
run:
	./app

# Clean
clean:
	rm -f $(OBJS) app