#include "LibKadane.h"
#include <iostream>

using namespace std;

int f_kadane(int* array, int n, int startIndex, int endIndex) {
    int max_sum = 0;
    int current_sum = 0;
    int temp_start = 0;

    for (int i = 0; i < n; i++) {
        current_sum += array[i];
        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1;
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
            startIndex = temp_start;
            endIndex = i;
        }
    }
    return max_sum;
}


int f_maxSubarraySum(int** array, int n, int m) {
    int max_sum = 0;
    int left, right, i;
    int* temp = new int[n];
    int startIndex = 0;
    int endIndex = 0;

    for (left = 0; left < m; left++) {
        for (i = 0; i < n; i++) {
            temp[i] = 0;
        }

        for (right = left; right < m; right++) {
            // Dodaje kolejn¹ kolumnê do tablicy temp
            for (i = 0; i < n; i++) {
                temp[i] += array[i][right];
            }

            // Stosuje algorytm Kadane na tablicy temp
            int current_sum = f_kadane(temp, n, startIndex, endIndex);

            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }

    delete[] temp;
    return max_sum;
}

void f_showResult(int result) {
    if (result > 0) {
        cout << result << endl;
    }
    else {
        cout << "0" << endl;
    }
}