
SRC=main.cpp maze.cpp camera.cpp lighting.cpp maze_builder.cpp
FLAGS=-lglut -lGL -lGLU -lGLEW
CC=g++
TARGET=maze

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(FLAGS)

clean:
	rm -f $(TARGET)
