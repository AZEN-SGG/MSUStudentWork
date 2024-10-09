all: main.o equal.o tools.o
	gcc main.o equal.o tools.o && del *.o
	
main.o: main.c
	gcc -c main.c

equal.o: equal.c
	gcc -c equal.c

tools.o: tools.c
	gcc -c tools.c