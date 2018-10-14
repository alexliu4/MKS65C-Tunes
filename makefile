all: tunes.o test.o
	gcc tunes.o test.o

list.o: tunes.c tunes.h
	gcc -c tunes.c

main.o: test.c tunes.h
	gcc -c test.c

clear:
	rm *.o

run:
	./a.out
