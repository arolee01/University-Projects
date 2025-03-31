#include "LibArray.h"
#include <iostream>
#include <climits>

using namespace std;


int** f_createArray(int n, int m) {
    int** array = new int* [n];

    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }
    return array;
}


void f_deleteArray(int** array, int n) {
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;
}

bool f_fillArray(int** array, int n, int m) {
    cout << "Enter array elements:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> array[i][j];
            // Sprawdza, czy wartoœæ mieœci siê w zakresie typu short (od -2^15 do 2^15)
            if (array[i][j] < SHRT_MIN || array[i][j] > SHRT_MAX) {
                cout << "Error: Data is out of range for short type!" << endl;
                return false;
            }
        }
    }
    return true;
}