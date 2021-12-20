all: stringProg main.o Minimal_sequence.o

stringProg: main.o Minimal_sequence.o
	gcc -Wall -o stringProg main.o Minimal_sequence.o

Minimal_sequence.o: Minimal_sequence.c Minimal_sequence.h
	gcc -Wall -c Minimal_sequence.c

main.o: main.c Minimal_sequence.h
	gcc -Wall -c main.c

.PHONY: clean

clean:
	rm -rf *.o *.a *.out stringProg