all: main.o solution_polynomial.o tools.o
	gcc main.o solution_polynomial.o tools.o && del *.o
	
main.o: main.c
	gcc -c main.c

solution_polynomial.o: solution_polynomial.c
	gcc -c solution_polynomial.c

tools.o: tools.c
	gcc -c tools.c