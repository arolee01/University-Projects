#include "LibTables.h"

int f_countOccurrences(int* arr, int size, int target) {
    int first = -1;
    int last = -1;

    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    if (left < size && arr[left] == target) {
        first = left;
    }
    else {
        return 0;
    }

    right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    last = right;

    return last - first + 1;
}

int f_interpolationSearch(int* arr, int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (arr[low] == arr[high]) {
            if (arr[low] == target) {
                return 0;
            }
            return -1;
        }

        int pos = low + static_cast<int>(((double)(target - arr[low]) * (high - low) / (arr[high] - arr[low])));

        if (pos < low) {
            pos = low;
        }
        if (pos > high) {
            pos = high;
        }

        if (arr[pos] == target) {
            return pos;
        }
        else if (arr[pos] < target) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }

    return -1;
}

int* f_removeDuplicates(int* arr, int size, int& newSize) {
    if (size == 0) {
        newSize = 0;
        return nullptr;
    }

    int* temp = new int[size];
    temp[0] = arr[0];
    newSize = 1;

    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {
            temp[newSize] = arr[i];
            newSize++;
        }
    }

    int* result = new int[newSize];
    for (int i = 0; i < newSize; i++) {
        result[i] = temp[i];
    }

    delete[] temp;
    return result;
}