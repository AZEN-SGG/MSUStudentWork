all: main.o exp_weigh_avg.o tools.o
	gcc main.o exp_weigh_avg.o tools.o && del *.o
	
main.o: main.c
	gcc -c main.c

exp_weigh_avg.o: exp_weigh_avg.c
	gcc -c exp_weigh_avg.c
	
tools.o: tools.c
	gcc -c tools.c