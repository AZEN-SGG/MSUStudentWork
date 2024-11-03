all: main.o max_distance.o tools.o
	gcc main.o max_distance.o tools.o && del *.o

main.o: main.c
	gcc -c main.c

max_distance.o: max_distance.c
	gcc -c max_distance.c

tools.o: tools.c
	gcc -c tools.c
