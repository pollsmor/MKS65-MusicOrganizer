ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o llist.o
	$(CC) -o mytunes main.o llist.o

main.o: main.c llist.h
	$(CC) -c main.c

llist.o: llist.c llist.h
	$(CC) -c llist.c

run:
	./mytunes

clean:
	rm *.o
	rm mytunes

memcheck:
	valgrind --leak-check=yes ./mytunes
