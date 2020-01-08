/*
Musaab Yousif   //name
CS 3240         //class
1/13/2020       //date
Assignment #1   //assignment title
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "apue.h"
#include "array.h"
#include "linked.h"
#include <pthread.h>



int main(int argc, char *argv[]){

int size = NULL;
double result;
pthread_t threads[2]; //2 new threads
pthread_create(&(threads[i]), NULL, &createArray); //create 2 new threads and run the array splitter through them

printf("\nrand %d", rand() % 2000 + 10000);
result = (double) rand() / RAND_MAX;
size = result;
}

double * createArray(int * size){

int i;
size = (double) (rand() % 2000) + 10000;

int *array = malloc(size * sizeof(*array));

for(i = 0; i < size; i++){
    array[i] = (double) rand() / RAND_MAX;
}
    return array, size;
}
