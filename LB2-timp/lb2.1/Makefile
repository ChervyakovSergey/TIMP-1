CC=g++
CFLAGS=-std=c++11 -Wall -Wextra
LDFLAGS=-std=c++11

all: gronsfeld

gronsfeld: main.o modGronsfeld.o
	$(CC) $(LDFLAGS) main.o modGronsfeld.o -o gronsfeld

main.o: main.cpp modGronsfeld.h
	$(CC) $(CFLAGS) -c main.cpp

modGronsfeld.o: modGronsfeld.cpp modGronsfeld.h
	$(CC) $(CFLAGS) -c modGronsfeld.cpp

clean:
	rm -f *.o gronsfeld

