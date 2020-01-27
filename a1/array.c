#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "array.h"


double * createArray(int size){
    int i;
    double *array = malloc(size * sizeof(double));
    for(i = 0; i < size; i++){
        array[i] = rand() % 2000 + 10000;
    }
return array;
}

int arrayProcess(double *array, int size){
    clock_t start, end;
    int timeUsed;
    start = clock();       
    struct arraysize thread1 = {array, size};

    printf("In array.\nSize: %i", size);

    pthread_t threadid;
    pthread_create(&threadid, NULL, arraySplit, (void *)&(thread1));

    pthread_join(threadid, NULL);

    end = clock();
    timeUsed = (end - start) / CLOCKS_PER_SEC;
    printf("Sort done.\n Time: %d", timeUsed);

    pthread_exit(0);
    printf("right before write to file");
    writeToFile(array, size);   
    return 0;

}  // returns 0 ok, -1 on error; return to main do not exit in this function

void * arraySplit(void * thread2){
    int i, j, k;
    struct arraysize * thread = thread2;

    int size1 = thread->size/2;
    
    if(size1 < 1000){
        for(i=1; i<size1-1; i++){
            k = thread->array[i];
            j = i-1;

            while(j >= 0 && thread->array[j] > k) {
                thread->array[j+1] = thread->array[j];
                j--;
            }
            thread->array[j+1] = k;
            }
        
    }
    else{
        size1 /= 2;
        
        double* array1 = malloc((size1)*sizeof(double));
        double* array2 = malloc((size1)*sizeof(double));
        array1 = thread->array;
        array2 = thread->array + size1+1;

        pthread_t threadid1, threadid2;
        struct arraysize threadSplit = {array1, size1};
        pthread_create(&threadid1, NULL, &arraySplit, (void *) &(threadSplit));
        threadSplit.array = array2;
        pthread_create(&threadid2, NULL, &arraySplit, (void *) &(threadSplit));

        pthread_join(threadid1, NULL);
        pthread_join(threadid2, NULL);

        mergeSorted(array1, array2, thread->array, size1, size1);
                
        pthread_exit(0);
        free(array1);
        free(array2);

        printf("right before write to file");
    }
    return NULL;  
}

double * mergeSorted(double *array1, double *array2, double *mergedArray, int size2, int size3){
        
        int i,j,k = 0;

        while (i < size2 && j < size3){
            if (array1[i] < array2[j]){
                mergedArray[k] = array1[i];
                i++;
                k++;
            }
            else {
                mergedArray[k] = array2[j];
                k++;
                j++;
            }
        }

        while (i < size2){
            mergedArray[k] = array1[i];
            k++;
            i++;
        }

       // while (j < size3){
         //   mergedArray[k] = array2[j];
           // k++;
            // j++;
       // }
        return mergedArray;
}

int writeToFile(double * array, int size){
    FILE* csv;

    csv = fopen("array.csv", "w");
    fwrite(array, sizeof(double), size, csv);
    fclose(csv);

    free(array);
    return 0;
    
}
