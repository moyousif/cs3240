#include <time.h>
#include <stdio.h>


int array(double * array, int size){

    clock_t start, end;
    double timeUsed;
    start = clock();

    printf("In array.\nSize: %i", size);

    

end = clock();
timeUsed = (end - start) / CLOCKS_PER_SEC;
printf("Sort done.\n Time: %d", timeUsed);

};  // returns 0 ok, -1 on error; return to main do not exit in this function


double * createArray(int *size);

