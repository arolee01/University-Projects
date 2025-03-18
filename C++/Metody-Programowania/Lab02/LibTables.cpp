#include "LibTables.h"
#include <cstddef> // dla nullptr

using namespace std;

void f_freeMemory(double** data, int rows) {
    if (data == nullptr) return;

    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

void f_copyTable(double** source, double** destination, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            destination[i][j] = source[i][j];
        }
    }
}

double** f_extractGrid(double** data, int gridIndex, int rows, int cols) {
    // Alokujemy pamiêæ dla pojedynczej siatki
    double** grid = new double* [rows];
    for (int i = 0; i < rows; i++) {
        grid[i] = new double[cols];

        // Kopiujemy dane
        for (int j = 0; j < cols; j++) {
            grid[i][j] = data[gridIndex * rows + i][j];
        }
    }

    return grid;
}