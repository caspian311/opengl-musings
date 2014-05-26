
SRC=main.cpp 
FLAGS=-lglut -lGL -lGLU -lGLEW
CC=g++
TARGET=maze

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(FLAGS)

clean:
	rm -f $(TARGET)
