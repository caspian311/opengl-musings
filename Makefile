
SRC=main.cpp maze.cpp camera.cpp lighting.cpp
FLAGS=-lglut -lGL -lGLU -lGLEW
CC=gcc
TARGET=maze

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
