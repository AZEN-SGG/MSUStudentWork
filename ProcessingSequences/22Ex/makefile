all: main.o make_increasing.o tools.o
	gcc main.o make_increasing.o tools.o && del *.o

main.o: main.c
	gcc -c main.c
	
make_increasing.o: make_increasing.c
	gcc -c make_increasing.c

tools.o: tools.c
	gcc -c tools.c