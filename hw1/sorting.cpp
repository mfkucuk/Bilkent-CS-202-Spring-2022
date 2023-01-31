/*
* Title: Sorting and Algorithm Efficiency
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 1
* Description: Implementation of sorting functions.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#include "sorting.h"

// Question 2 - Part A
void insertionSort(int* arr, const int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i;
        moveCount++;

        for (; j > 0; j--) {
            compCount++;
            if (arr[j - 1] > key) {
                arr[j] = arr[j - 1];
                moveCount++;
            }
            else {
                break;
            }
        }

        arr[j] = key;
        moveCount++;
    }
}

void bubbleSort(int* arr, const int size, int &compCount, int &moveCount) {
    int temp;
    bool swap;
    compCount = 0;
    moveCount = 0;

    for (int i = 0; i < size; i++) {
        swap = false;

        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                moveCount += 3;
                swap = true;
            }
            compCount++;
        }

        if (!swap) {
            break;
        }
    }
}

void mergeSort(int* arr, const int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;
    mergeSort(arr, 0, size - 1, compCount, moveCount);
}

void mergeSort(int* arr, int first, int last, int &compCount, int &moveCount) {
    if (first < last) {

        int mid = (first + last) / 2;

        // Divide
        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid+1, last, compCount, moveCount);

        // Conquer
        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void merge(int* arr, int first, int mid, int last, int &compCount, int &moveCount) {
    int tempArr[40000];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    for (; (first1 <= last1) && (first2 <= last2); index++) {
        if (arr[first1] < arr[first2]) {
            tempArr[index] = arr[first1];
            first1++;
        }
        else {
            tempArr[index] = arr[first2];
            first2++;
        }
        compCount++;
        moveCount++;
    }

    for (; first1 <= last1; first1++, index++) {
        tempArr[index] = arr[first1];
        moveCount++;
    }


    for (; first2 <= last2; first2++, index++) {
        tempArr[index] = arr[first2];
        moveCount++;
    }

    for (index = first; index <= last; index++) {
        arr[index] = tempArr[index];
        moveCount++;
    }
}

void quickSort(int* arr, const int size, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;
    quickSort(arr, 0, size - 1, compCount, moveCount);
}

void quickSort(int* arr, int first, int last, int &compCount, int &moveCount) {
    int pivotIndex;

    if (first < last) {
        partition(arr, first, last, pivotIndex, compCount, moveCount);

        quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

void partition(int* arr, int first, int last, int& pivotIndex, int &compCount, int &moveCount) {
    pivotIndex = first;

    int pivot = arr[first];
    int temp;
    int lastS1 = first;
    int unknown = first + 1;

    moveCount++;

    for (; unknown <= last; unknown++) {
        if (arr[unknown] < pivot) {
            lastS1++;
            temp = arr[unknown];
            arr[unknown] = arr[lastS1];
            arr[lastS1] = temp;
            moveCount += 3;
        }
        compCount++;
    }
    temp = arr[first];
    arr[first] = arr[lastS1];
    arr[lastS1] = temp;
    pivotIndex = lastS1;
    moveCount += 3;
}

// Question 2 - Part B
void displayArray(const int* arr, const int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            cout << arr[i];
        }
        else {
            cout << arr[i] << ", ";
        }
    }

    cout << " ]" << endl;
}

void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
    int randomInt;

    srand (time(NULL));

    for (int i = 0; i < size; i++) {
        randomInt = rand() % 40000 + 1;
        arr1[i] = randomInt;
        arr2[i] = randomInt;
        arr3[i] = randomInt;
        arr4[i] = randomInt;
    }
}

void createAlmostSortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
    int randIndex1;
    int randIndex2;
    int temp;

    srand (time(NULL));

    for (int i = 0; i < size; i++) {
        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
        arr4[i] = i;    
    }

    for (int i = 0; i < (size / 20); i++) {
        randIndex1 = rand() % size;
        randIndex2 = rand() % size;
        temp = arr1[randIndex1];
        arr1[randIndex1] = arr1[randIndex2];
        arr1[randIndex2] = temp;

        temp = arr2[randIndex1];
        arr2[randIndex1] = arr2[randIndex2];
        arr2[randIndex2] = temp;

        temp = arr3[randIndex1];
        arr3[randIndex1] = arr3[randIndex2];
        arr3[randIndex2] = temp;

        temp = arr4[randIndex1];
        arr4[randIndex1] = arr4[randIndex2];
        arr4[randIndex2] = temp;
    }
}

void createAlmostUnsortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
    int randIndex1;
    int randIndex2;
    int temp;

    srand (time(NULL));

    for (int i = 0; i < size; i++) {
        arr1[i] = size - (i + 1);
        arr2[i] = size - (i + 1);
        arr3[i] = size - (i + 1);
        arr4[i] = size - (i + 1); 
    }

    for (int i = 0; i < (size / 20); i++) {
        randIndex1 = rand() % size;
        randIndex2 = rand() % size;
        temp = arr1[randIndex1];
        arr1[randIndex1] = arr1[randIndex2];
        arr1[randIndex2] = temp;

        temp = arr2[randIndex1];
        arr2[randIndex1] = arr2[randIndex2];
        arr2[randIndex2] = temp;

        temp = arr3[randIndex1];
        arr3[randIndex1] = arr3[randIndex2];
        arr3[randIndex2] = temp;

        temp = arr4[randIndex1];
        arr4[randIndex1] = arr4[randIndex2];
        arr4[randIndex2] = temp;
    }
}