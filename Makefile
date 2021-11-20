CC = gcc
CFLAGS = -Wall -Wextra 
LIBS = `pkg-config allegro-5 allegro_font-5 allegro_image-5 allegro_primitives-5 --libs --cflags`
LIBS2 = -lm
all: lab

lab: prolab2.o
	$(CC) $(CFLAGS) $(LIBS2) $(LIBS) -o lab lab.o

lab.o: prolab.c
	$(CC) $(CFLAGS) -c lab.c

test: test.o
	$(CC) $(CFLAGS) $(LIBS) $(LIBS2) -o test test.o

test.o: test.c
	$(CC) $(CFLAGS) -c test.c


clean:
	rm -f test *.o

