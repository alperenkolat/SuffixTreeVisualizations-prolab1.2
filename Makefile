CC = gcc
CFLAGS = -Wall -Wextra 
LIBS = `pkg-config allegro-5 allegro_font-5 allegro_image-5 allegro_primitives-5 --libs --cflags`
LIBS2 = -lm
all: prolab2

prolab2: prolab2.o
	$(CC) $(CFLAGS) $(LIBS2) $(LIBS) -o prolab2 prolab2.o

prolab.o: prolab2.c
	$(CC) $(CFLAGS) -c prolab2.c



clean:
	rm -f test *.o

