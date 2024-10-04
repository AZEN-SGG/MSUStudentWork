all: main.o max_deviation.o get_file.o
	gcc main.o max_deviation.o get_file.o && del *.o

main.o: main.c
	gcc -c main.c

max_deviation.o: max_deviation.c
	gcc -c max_deviation.c

get_file.o: get_file.c
	gcc -c get_file.c