#ifndef ARRAY_H
#define ARRAY_H

struct arraysize {double * array; int size; };
double * createArray(int size);
int arrayProcess(double * array, int size);
void * arraySplit(void * threads);
double * mergeSorted(double *array1, double *array2, double *mergedArray, int size1, int size2);
int writeToFile(double * array, int size);

#endif