
SRC=main.cpp maze.cpp camera.cpp lighting.cpp
FLAGS=-lglut -lGL -lGLU -lGLEW
CC=gcc
TARGET=maze

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(FLAGS)

clean:
	rm -f $(TARGET)
