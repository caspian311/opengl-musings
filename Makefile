
all: example

example: example.cpp
	gcc -lglut -lGL -lGLU -lGLEW example.cpp -o example  

clean:
	rm -f example
