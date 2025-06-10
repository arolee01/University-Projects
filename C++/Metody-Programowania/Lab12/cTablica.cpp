#include "cTablica.h"
#include <algorithm>

cTablica::cTablica() {}

cTablica::cTablica(const std::vector<int>& inputData) : data(inputData) {}

void cTablica::setData(const std::vector<int>& inputData) {
    data = inputData;
}

std::vector<int> cTablica::getData() const {
    return data;
}

std::pair<long long, long long> cTablica::shakerSort() {
    std::vector<int> arr = data;
    long long comparisons = 0;
    long long swaps = 0;

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        // Przejście w prawo
        for (int i = left; i < right; i++) {
            comparisons++;
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swaps++;
            }
        }
        right--;

        // Przejście w lewo
        for (int i = right; i > left; i--) {
            comparisons++;
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swaps++;
            }
        }
        left++;
    }

    data = arr;
    return {comparisons, swaps};
}

int cTablica::partitionLomuto(std::vector<int>& arr, int low, int high,
                             long long& comparisons, long long& swaps) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            if (i != j) {
                std::swap(arr[i], arr[j]);
                swaps++;
            }
        }
    }

    if (i + 1 != high) {
        std::swap(arr[i + 1], arr[high]);
        swaps++;
    }

    return i + 1;
}

int cTablica::partitionHoare(std::vector<int>& arr, int low, int high,
                            long long& comparisons, long long& swaps) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
            comparisons++;
        } while (arr[i] < pivot);

        do {
            j--;
            comparisons++;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        std::swap(arr[i], arr[j]);
        swaps++;
    }
}

void cTablica::quickSortLomuto(std::vector<int>& arr, int low, int high,
                              long long& comparisons, long long& swaps) {
    if (low < high) {
        int pi = partitionLomuto(arr, low, high, comparisons, swaps);
        quickSortLomuto(arr, low, pi - 1, comparisons, swaps);
        quickSortLomuto(arr, pi + 1, high, comparisons, swaps);
    }
}

void cTablica::quickSortHoare(std::vector<int>& arr, int low, int high,
                             long long& comparisons, long long& swaps) {
    if (low < high) {
        int pi = partitionHoare(arr, low, high, comparisons, swaps);
        quickSortHoare(arr, low, pi, comparisons, swaps);
        quickSortHoare(arr, pi + 1, high, comparisons, swaps);
    }
}

std::pair<long long, long long> cTablica::quickSortLomuto() {
    std::vector<int> arr = data;
    long long comparisons = 0;
    long long swaps = 0;

    if (arr.size() > 1) {
        quickSortLomuto(arr, 0, arr.size() - 1, comparisons, swaps);
    }

    data = arr;
    return {comparisons, swaps};
}

std::pair<long long, long long> cTablica::quickSortHoare() {
    std::vector<int> arr = data;
    long long comparisons = 0;
    long long swaps = 0;

    if (arr.size() > 1) {
        quickSortHoare(arr, 0, arr.size() - 1, comparisons, swaps);
    }

    data = arr;
    return {comparisons, swaps};
}

void cTablica::heapify(std::vector<int>& arr, int n, int i,
                      long long& comparisons, long long& swaps) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comparisons++;
        if (arr[left] > arr[largest]) {
            largest = left;
        }
    }

    if (right < n) {
        comparisons++;
        if (arr[right] > arr[largest]) {
            largest = right;
        }
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        swaps++;
        heapify(arr, n, largest, comparisons, swaps);
    }
}

void cTablica::buildMaxHeap(std::vector<int>& arr, int n,
                           long long& comparisons, long long& swaps) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons, swaps);
    }
}

std::pair<long long, long long> cTablica::heapSort() {
    std::vector<int> arr = data;
    long long comparisons = 0;
    long long swaps = 0;
    int n = arr.size();

    if (n <= 1) {
        data = arr;
        return {comparisons, swaps};
    }

    // Buduj kopiec
    buildMaxHeap(arr, n, comparisons, swaps);

    // Jeden po drugim wyciągaj elementy z kopca
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        swaps++;
        heapify(arr, i, 0, comparisons, swaps);
    }

    data = arr;
    return {comparisons, swaps};
}

bool cTablica::isSorted() const {
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i] < data[i - 1]) {
            return false;
        }
    }
    return true;
}