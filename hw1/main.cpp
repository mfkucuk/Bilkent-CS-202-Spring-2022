/*
* Title: Sorting and Algorithm Efficiency
* Author: Mehmet Feyyaz Küçük
* ID: 22003550
* Section: 2
* Assignment: 1
* Description: Main file for testing the sorting algorithms.
*/

#include <iostream>
#include <ctime>
#include <stdio.h>
using namespace std;

#include "sorting.h"

void performanceAnalysis(int* arr1, int* arr2, int* arr3, int* arr4, void (*CreateArray)(int*&, int*&, int*&, int*&, const int)) {

    double duration;
    clock_t startTime;

    int compCount;
    int moveCount;
    int performanceInfo[4][8][4];

    for (int i = 5000; i <= 40000; i += 5000) {
        CreateArray(arr1, arr2, arr3, arr4, i);

        // Insertion
        startTime = clock();

        insertionSort(arr1, i, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        performanceInfo[0][i / 5000 - 1][0] = i;
        performanceInfo[0][i / 5000 - 1][1] = duration;
        performanceInfo[0][i / 5000 - 1][2] = compCount;
        performanceInfo[0][i / 5000 - 1][3] = moveCount;

        startTime = clock();

        bubbleSort(arr2, i, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        performanceInfo[1][i / 5000 - 1][0] = i;
        performanceInfo[1][i / 5000 - 1][1] = duration;
        performanceInfo[1][i / 5000 - 1][2] = compCount;
        performanceInfo[1][i / 5000 - 1][3] = moveCount;

        startTime = clock();
        mergeSort(arr3, i, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        performanceInfo[2][i / 5000 - 1][0] = i;
        performanceInfo[2][i / 5000 - 1][1] = duration;
        performanceInfo[2][i / 5000 - 1][2] = compCount;
        performanceInfo[2][i / 5000 - 1][3] = moveCount;

        startTime = clock();
        quickSort(arr4, i, compCount, moveCount);
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

        performanceInfo[3][i / 5000 - 1][0] = i;
        performanceInfo[3][i / 5000 - 1][1] = duration;
        performanceInfo[3][i / 5000 - 1][2] = compCount;
        performanceInfo[3][i / 5000 - 1][3] = moveCount;
    }

    for (int i = 0; i < 4; i++) {
        cout << "---------------------------------------------------------------------------------" << endl;
        if (i == 0) {
            cout << "Analysis of Insertion Sort" << endl;
        }
        else if (i == 1) {
            cout << "Analysis of Bubble Sort" << endl;
        }
        else if (i == 2) {
            cout << "Analysis of Merge Sort" << endl;
        }
        else if (i == 3) {
            cout << "Analysis of Quick Sort" << endl;
        }

        printf("%20s %20s %20s %20s", "Array Size", "Elapsed Time", "compCount", "moveCount");
        cout << endl;
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 4; k++) {
                if (k == 1) {
                    printf("%20d ms", performanceInfo[i][j][k]);
                }
                else {
                    printf("%20d", performanceInfo[i][j][k]);
                }
            }
            cout << endl;
        }
    }
}

int main() {

    // Question 2 - Part C
    int arrSize = 16;
    int arrInsertion[] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int arrBubble[] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int arrMerge[] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int arrQuick[] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    int compCount;
    int moveCount;

    cout << "Insertion Sort" << endl;
    insertionSort(arrInsertion, arrSize, compCount, moveCount);
    cout << "Comp Count: " << compCount << endl;
    cout << "Move Count: " << moveCount << endl;
    displayArray(arrInsertion, arrSize);
    cout << endl;

    cout << "Bubble Sort" << endl;
    bubbleSort(arrBubble, arrSize, compCount, moveCount);
    cout << "Comp Count: " << compCount << endl;
    cout << "Move Count: " << moveCount << endl;
    displayArray(arrBubble, arrSize);
    cout << endl;

    cout << "Merge Sort" << endl;
    mergeSort(arrMerge, arrSize, compCount, moveCount);
    cout << "Comp Count: " << compCount << endl;
    cout << "Move Count: " << moveCount << endl;
    displayArray(arrMerge, arrSize);
    cout << endl;

    cout << "Quick Sort" << endl;
    quickSort(arrQuick, arrSize, compCount, moveCount);
    cout << "Comp Count: " << compCount << endl;
    cout << "Move Count: " << moveCount << endl;
    displayArray(arrQuick, arrSize);
    cout << endl;


    // Question 2 - Part D
    const int size = 40000;
    int* arr1 = new int[size];
    int* arr2 = new int[size];
    int* arr3 = new int[size];
    int* arr4 = new int[size];
    
    cout << "Performance Analysis with random arrays" << endl;
    performanceAnalysis(arr1, arr2, arr3, arr4, createRandomArrays);

    cout << "Performance Analysis with almost sorted arrays" << endl;
    performanceAnalysis(arr1, arr2, arr3, arr4, createAlmostSortedArrays);

    cout << "Performance Analysis with almost unsorted arrays" << endl;
    performanceAnalysis(arr1, arr2, arr3, arr4, createAlmostUnsortedArrays);

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
}