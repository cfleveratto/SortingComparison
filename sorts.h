#ifndef INCLUDED_SORTING
#define INCLUDED_SORTING

void swap (int & num1, int & num2);

void bubbleSort (int List[], int numElements);

void heapify (int heap[], int atIndex);

void reheapify (int heap[], int heapElements, int atIndex);

void heapSort (int List[], int numElements);

#endif
