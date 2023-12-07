
CC = g++
CFLAGS = -std=c++17

SOURCES = ./main.cpp \
		  ./image.cpp \
		  ./util.cpp \
		  ./geometry.cpp \
		  ./renderer.cpp

EXECUTABLE = raytrasor.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ 

clean:
	del $(EXECUTABLE) *.ppm