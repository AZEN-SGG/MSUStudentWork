all: main.o max_difference.o get_file.o
	gcc main.o max_difference.o get_file.o && del *.o

main.o: main.c
	gcc -c main.c

max_difference.o: max_difference.c
	gcc -c max_difference.c

get_file.o: get_file.c
	gcc -c get_file.c