CC=gcc
CFLAGS= -g -Wall -Werror -pedantic
CFLAGS += -pthread
LDLIBS+= -lpthread -lrt
#CFLAGS= -O

a1:	a1.o array.o error.o

a1.o: apue.h array.h
array.o: array.c apue.h


clean:
		rm -f *.o a1 *.csv

run:
		./source