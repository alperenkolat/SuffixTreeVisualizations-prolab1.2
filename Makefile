CC = gcc
CFLAGS = -Wall -Wextra 
LIBS = `pkg-config allegro-5 allegro_font-5 allegro_image-5 allegro_primitives-5 --libs --cflags`
LIBS2 = -lm
all: lab

lab: prolab2.o
	$(CC) $(CFLAGS) $(LIBS2) $(LIBS) -o lab lab.o

lab.o: prolab2.c
	$(CC) $(CFLAGS) -c lab.c



clean:
	rm -f test *.o

