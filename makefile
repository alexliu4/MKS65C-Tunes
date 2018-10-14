all: tunes.o test.o
	gcc tunes.o test.o -o tunes

run: all
	./tunes
	clean

tunes.o: tunes.c tunes.h
	gcc -c tunes.c

test.o: test.o
	gcc -c test.c

clean:
	rm *.o
	rm struct
