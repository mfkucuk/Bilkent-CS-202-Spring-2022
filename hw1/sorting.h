/*
* Title: Sorting and Algorithm Efficiency
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 1
* Description: Prototypes for sorting functions.
*/


#ifndef SORTING_H
#define SORTING_H

void insertionSort(int* arr, const int size, int &compCount, int &moveCount);
void bubbleSort(int* arr, const int size, int &compCount, int &moveCount);
void mergeSort(int* arr, const int size, int &compCount, int &moveCount);
void mergeSort(int* arr, int first, int last, int &compCount, int &moveCount);
void merge(int* arr, int first, int mid, int last, int &compCount, int &moveCount);
void quickSort(int* arr, const int size, int &compCount, int &moveCount);
void quickSort(int* arr, int first, int last, int &compCount, int &moveCount);
void partition(int* arr, int first, int last, int& pivotIndex, int &compCount, int &moveCount);

void displayArray(const int* arr, const int size);
void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void createAlmostSortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void createAlmostUnsortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);

#endif