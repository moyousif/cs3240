CC=gcc
CFLAGS= -g -Wall -Werror -pedantic
CFLAGS += -pthread
LDLIBS+= -lpthread -lrt
#CFLAGS= -O

a1:	a1.o array.o error.o

a2.o: card.h parser.h
parser.o: card.h .c apue.h


clean:
		rm -f *.o a2 *.csv

run:
		./a2