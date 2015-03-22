# Makefile for intstack module - by DPH, modified Spring 2014
# It compiles the module and creates the intstackdr executable
# Edited by Dylan Woodbury

store : store.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o store store.o List.o

Listdr : Listdr.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o Listdr Listdr.o List.o

List.o : List.h List.c
	gcc -c -ansi -Wall -Wextra -pedantic List.c

store.o : store.c
	gcc -c -ansi -Wall -Wextra -pedantic store.c

Listdr.o : Listdr.c
	gcc -c -ansi -Wall -Wextra -pedantic Listdr.c

clean :
	rm store Listdr Listdr.o store.o List.o

# an old version of the makefile used the additional gcc option
# -I/usr/lang/SC1.0/ansi_include but it is not needed on my system
# we should double check that that option is not needed on the cats system
