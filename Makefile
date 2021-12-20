

all: stringProg

stringProg: main.o Minimal_sequence.a 
	gcc -wall -o stringProg main.o Minimal_sequence.a 

Minimal_sequence.a: Minimal_sequence.o
	ar rcs Minimal_sequence.a Minimal_sequence.o

Minimal_sequence.o: Minimal_sequence.c Minimal_sequence.h
	gcc -wall -c Minimal_sequence.c

main.o: main.c Minimal_sequence.h
	gcc -wall -c main.c

.PHONY: clean

clean: 
	rm -rf *.o *.a stringProg

© 2021 GitHub, Inc.
Terms
Privacy
