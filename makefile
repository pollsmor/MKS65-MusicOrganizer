ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o llist.o library.o
	$(CC) -o mytunes main.o llist.o library.o

main.o: main.c llist.h library.h
	$(CC) -c main.c library.c

llist.o: llist.c llist.h library.h
	$(CC) -c llist.c

library.o: library.c library.h llist.h
	$(CC) -c library.c

run:
	./mytunes

clean:
	rm *.o
	rm mytunes

memcheck:
	valgrind --leak-check=yes ./mytunes
