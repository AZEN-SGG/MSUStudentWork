CFLAGS = -mfpmath=sse \
         -fstack-protector-all \
         -W \
         -Wall \
         -Wextra \
         -Wunused \
         -Wcast-align \
         -Werror \
         -pedantic \
         -pedantic-errors \
         -Wfloat-equal \
         -Wpointer-arith \
         -Wformat-security \
         -Wmissing-format-attribute \
         -Wformat=1 \
         -Wwrite-strings \
         -Wcast-align \
         -Wno-long-long \
         -std=gnu99 \
         -Wstrict-prototypes \
         -Wmissing-prototypes \
         -Wmissing-declarations \
         -Wold-style-definition \
         -Wdeclaration-after-statement \
         -Wbad-function-cast \
         -Wnested-externs \
		 -O3 \
		 -D_DEBUG -g \
		 -c

all: main.o SCP.o hope.o tools.o
	gcc main.o SCP.o hope.o tools.o -lssp && del *.o
	a.exe

main.o: main.c
	gcc $(CFLAGS) main.c

SCP.o: SCP.c
	gcc $(CFLAGS) SCP.c

hope.o: hope.c
	gcc $(CFLAGS) hope.c

tools.o: tools.c
	gcc $(CFLAGS) tools.c
