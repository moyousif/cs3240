CC=gcc
CFLAGS= -g -Wall -Werror -pedantic -pthreads
LDLIBS= -lpthread -rt
#CFLAGS= -O

a1:	a1.o array.o error.o linked.O

a1.o: apue.h array.h linked.h
array.o: array.h
linked.o: linked.h


clean:
		rm *.o a1

run:
		./a1