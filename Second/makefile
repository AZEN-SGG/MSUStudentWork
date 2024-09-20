all: main.o count_func.o
	gcc main.o count_func.o && del *.o
	
main.o: main.c
	gcc -c main.c

count_func.o: count_func.c
	gcc -c count_func.c