
CC = g++
CFLAGS = -std=c++17

SOURCES = ./src/main.cpp \
		  ./src/image.cpp \
		  ./src/util.cpp \
		  ./src/geometry.cpp \
		  ./src/renderer.cpp

EXECUTABLE = raytrasor.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ 

clean:
	del $(EXECUTABLE) *.ppm