
.PHONY: run
run: Minimal_sequence.c 
	 gcc Minimal_sequence.c -lm
	./a.out
# all: stringProg

# stringProg: main.o string_lib.a 
# 	$gcc $-Wall -o stringProg main.o string_lib.a 

# string_lib.a: string_lib.o
# 	ar rcs string_lib.a string_lib.o

# string_lib.o: string_lib.c string_lib.h
# 	$gcc $-Wall -c string_lib.c

# main.o: main.c string_lib.h
# 	$gcc $-Wall -c main.c

# .PHONY: clean

# clean: 
# 	rm -rf *.o *.a stringProg
