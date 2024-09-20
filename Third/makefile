all: main.o count_max_local.o get_file.o
	gcc main.o count_max_local.o get_file.o && del *.o

main.o: main.c
	gcc -c main.c

count_max_local.o: count_max_local.c
	gcc -c count_max_local.c

get_file.o: get_file.c
	gcc -c get_file.c