#ifndef ARRAY_H
#define ARRAY_H

double * createArray(int size);
int array(double * array, int size);
void arraySplit(double * array, int size);
void mergeSorted(double *array1, double *array2, double *mergedArray, int size1, int size2);
int writeToFile(double * array, int * size);

#endif