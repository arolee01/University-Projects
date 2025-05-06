#include "search_functions.h"
#include <iostream>

using namespace std;

Position findFirstRecursive(int** matrix, int rows, int cols, int target, int r, int c) {
    // Rekurencyjne przeszukiwanie od lewego górnego rogu
    if (r >= rows) return { -1, -1 }; // Koniec tablicy
    if (c >= cols) return findFirstRecursive(matrix, rows, cols, target, r + 1, 0); // PrzejdŸ do nastêpnego wiersza

    if (matrix[r][c] == target) return { r, c }; // Znaleziono element
    return findFirstRecursive(matrix, rows, cols, target, r, c + 1); // Przesuñ siê w prawo
}

Position findLastRecursive(int** matrix, int rows, int cols, int target, int r, int c) {
    // Rekurencyjne przeszukiwanie od prawego dolnego rogu
    if (r == -1 && c == -1) { r = rows - 1; c = cols - 1; } // Inicjalizacja pozycji startowej
    if (r < 0) return { -1, -1 }; // Koniec tablicy
    if (c < 0) return findLastRecursive(matrix, rows, cols, target, r - 1, cols - 1); // PrzejdŸ do poprzedniego wiersza

    if (matrix[r][c] == target) return { r, c }; // Znaleziono element
    return findLastRecursive(matrix, rows, cols, target, r, c - 1); // Przesuñ siê w lewo
}

Position findFirstIterative(int** matrix, int rows, int cols, int target) {
    // Optymalne wyszukiwanie wykorzystuj¹ce posortowanie tablicy
    int r = 0, c = cols - 1; // Start z prawego górnego rogu

    while (r < rows && c >= 0) {
        if (matrix[r][c] == target) {
            // Znaleziono - szukamy pierwszego wyst¹pienia w wierszu
            while (c > 0 && matrix[r][c - 1] == target) c--;
            return { r, c };
        }
        else if (matrix[r][c] < target) r++; // Przesuñ siê w dó³
        else c--; // Przesuñ siê w lewo
    }
    return { -1, -1 }; // Element nie znaleziony
}

Position findLastIterative(int** matrix, int rows, int cols, int target) {
    // Optymalne wyszukiwanie wykorzystuj¹ce posortowanie tablicy
    int r = rows - 1, c = 0; // Start z lewego dolnego rogu

    while (r >= 0 && c < cols) {
        if (matrix[r][c] == target) {
            // Znaleziono - szukamy ostatniego wyst¹pienia w wierszu
            while (c < cols - 1 && matrix[r][c + 1] == target) c++;
            return { r, c };
        }
        else if (matrix[r][c] < target) c++; // Przesuñ siê w prawo
        else r--; // Przesuñ siê w górê
    }
    return { -1, -1 }; // Element nie znaleziony
}

void printResult(const char* prefix, int target, Position pos) {
    // Formatowanie wyniku zgodnie z wymaganiami
    cout << prefix << ": ";
    if (pos.row == -1) {
        cout << "nie ma " << target << endl;
    }
    else {
        cout << target << " w (" << pos.row << "," << pos.col << ")" << endl;
    }
}