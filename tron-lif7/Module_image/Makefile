all: exemple.out test.out

OPT = -Wall -ansi -pedantic -ggdb

exemple.out: main.o image.o
	gcc obj/Debug/main.o obj/Debug/image.o -o bin/exemple

test.out: maintest.o image.o
	gcc obj/Debug/maintest.o obj/Debug/image.o -o bin/test

maintest.o: src/test.c src/image.h
	gcc -c $(OPT) -o obj/Debug/maintest.o src/test.c

main.o: src/main.c src/image.h
	gcc -c $(OPT) -o obj/Debug/main.o src/main.c 

image.o: src/image.c src/image.h src/pixel.h
	gcc -c $(OPT) -o obj/Debug/image.o src/image.c 

clean:
	/obj/Debug/src/rm -rf *.o main

