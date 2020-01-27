/*
Musaab Yousif   //name
CS 3240         //class
1/29/2020       //date
Assignment #2   //assignment title
*/

#include <stdio.h>
#include "card.h"
#include "apue.h"

#define MAX_CARDS 1616

int main(int argc, char * argv[]){
    int* cardptr;
    cardptr = (CARD*)malloc(MAX_CARDS*sizeof(CARD));
    CARD cards[MAX_CARDS];

    FILE *cardfile;
    cardfile = fopen("cards.csv", "r");

    free(cardptr);
    fclose(cardfile);
    return 0;
}