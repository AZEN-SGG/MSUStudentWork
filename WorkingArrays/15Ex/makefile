all: main.o replace_local_min.o tools.o
	gcc main.o replace_local_min.o tools.o && del *.o

main.o: main.c
	gcc -c main.c
	
replace_local_min.o: replace_local_min.c
	gcc -c replace_local_min.c

tools.o: tools.c
	gcc -c tools.c