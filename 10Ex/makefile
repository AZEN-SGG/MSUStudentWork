all: main.o count_between.o tools.o
	gcc main.o count_between.o tools.o && del *.o
	
main.o: main.c
	gcc -c main.c
	
count_between.o: count_between.c
	gcc -c count_between.c

tools.o: tools.c
	gcc -c tools.c