all: tunes.o test.o
	gcc tunes.o test.o -o tunes

list.o: tunes.c tunes.h
	gcc -g tunes.c

main.o: test.c tunes.h
	gcc -g test.c

clear:
	rm *.o
	rm tunes

run:
	./tunes
