all: main.o local_minimum.o tools.o
	gcc main.o local_minimum.o tools.o && del *.o
	
main.o: main.c
	gcc -c main.c

local_minimum.o: local_minimum.c
	gcc -c local_minimum.c

tools.o: tools.c
	gcc -c tools.c