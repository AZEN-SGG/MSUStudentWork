all: main.o solve_polynomial.o tools.o
	gcc main.o solve_polynomial.o tools.o && del *.o
	
main.o: main.c
	gcc -c main.c

solve_polynomial.o: solve_polynomial.c
	gcc -c solve_polynomial.c

tools.o: tools.c
	gcc -c tools.c