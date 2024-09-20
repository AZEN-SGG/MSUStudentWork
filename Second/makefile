all: main.o count_elements.o get_file.o
	gcc main.o count_elements.o get_file.o && del *.o

main.o: main.c
	gcc -c main.c
	
count_elements.o: count_elements.c
	gcc -c count_elements.c

get_file.o: get_file.c
	gcc -c get_file.c