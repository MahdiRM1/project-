CC = gcc          # کامپایلر
CFLAGS = -Wall    # نمایش هشدارها

all: program

program: main.o printmap.o generateArray.o road.o
	$(CC) -o program main.o printmap.o generateArray.o road.o

main.o: main.c printmap.h generateArray.h road.h
	$(CC) $(CFLAGS) -c main.c

printmap.o: printmap.c printmap.h
	$(CC) $(CFLAGS) -c printmap.c

generateArray.o: generateArray.c generateArray.h
	$(CC) $(CFLAGS) -c generateArray.c

road.o: road.c road.h
	$(CC) $(CFLAGS) -c road.c

clean:
	rm -f *.o program