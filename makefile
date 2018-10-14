all: tunes.o test.o list.o
	gcc  list.o tunes.o test.o -o tunes

tunes.o: tunes.c tunes.h
	gcc -c tunes.c

list.o: list.c list.h
	gcc -c list.c

test.o: test.c tunes.h
	gcc -c test.c

clean:
	rm *.o
	rm tunes

run: all
	./tunes
	make clean
