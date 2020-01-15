#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * arraySplit(double *array, int *size);
void mergeSorted(double *array1, double *array2, double *mergedArray, int size1, int size2);
int writeToFile(double * array, int * size);

double * createArray(int size){
    int i;
    double *array = malloc(size * sizeof(double));
    for(i = 0; i < size; i++){
        array[i] = (double) rand() / RAND_MAX;
    }
return array;
}

int array(double *array, int size){
    clock_t start, end;
    int timeUsed;
    start = clock();
    struct arraysize {double *array; int size; };
    struct arraysize threads = {array, size};

    printf("In array.\nSize: %i", size);

    while(size > 1000){
    pthread_t threadid;
    pthread_create(&threadid, NULL, &arraySplit, (void *) &(threads));

    pthread_join(threadid, NULL);

    }
    end = clock();
    timeUsed = (end - start) / CLOCKS_PER_SEC;
    printf("Sort done.\n Time: %d", timeUsed);

    return 0;

}  // returns 0 ok, -1 on error; return to main do not exit in this function

void * arraySplit(double *array, int *size){
    int i, j, k;
    struct arraysize {double *array; int size; };
    
    if(*size < 1000){
        for(i=1; i<*size-1; i++){
            k = array[i];
            j = i-1;

            while(j >= 0 && array[j] > k) {
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = k;
            }
        
    }
    else{
        *size /= 2;
        
        double* array1 = malloc((*size)*sizeof(double));
        double* array2 = malloc((*size)*sizeof(double));
        array1 = array;
        array2 = array + *size;

        pthread_t threadid1, threadid2;
        struct arraysize threadSplit = {array1, *size};
        pthread_create(&threadid1, NULL, &arraySplit, (void *) &(threadSplit));
        threadSplit.array = array2;
        pthread_create(&threadid2, NULL, &arraySplit, (void *) &(threadSplit));

        pthread_join(threadid1, NULL);
        pthread_join(threadid2, NULL);

        mergeSorted(array1, array2, array, *size, *size);

        free(array1);
        free(array2);
    }
    return 0;  
}

void mergeSorted(double *array1, double *array2, double *mergedArray, int size1, int size2){
        
        int i,j,k = 0;

        while (i < size1 && j < size2){
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

        while (i < size1){
            mergedArray[k] = array1[i];
            k++;
            i++;
        }

        while (j < size2){
            mergedArray[k] = array2[j];
            k++;
            j++;
        }
}

int writeToFile(double * array, int * size){
    FILE* csv;

    csv = fopen("array.csv", "w");
    fwrite(array, sizeof(double), *size, csv);
    fclose(csv);

    free(array);
    return 0;
    
}
