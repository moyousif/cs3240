/*
Musaab Yousif   //name
CS 3240         //class
1/13/2020       //date
Assignment #1   //assignment title
*/

#include <stdio.h>
#include <math.h>
#include "apue.h"
#include "array.h"

int main(int argc, char *argv[]){
    int size = 0;
    size = (int) rand() % 2000 + 10000;

    arrayProcess((createArray(size)), size);
}
