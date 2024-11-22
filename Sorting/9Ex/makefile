all: main.o seagwithsob.o tools.o
	gcc main.o seagwithsob.o tools.o && del *.o
	a.exe

main.o: main.c
	gcc -c main.c

seagwithsob.o: seagwithsob.c
	gcc -c seagwithsob.c

tools.o: tools.c
	gcc -c tools.c
