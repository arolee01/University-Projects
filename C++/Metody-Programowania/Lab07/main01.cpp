#include <iostream>
#include "search_functions.h"

using namespace std;

int main() {

    int data_sets;
    cin >> data_sets;

    while (data_sets--) {
        int rows, cols;
        cin >> rows >> cols;

        int** matrix = new int* [rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
            }
        }

        int target;
        cin >> target;

        Position first_rec = findFirstRecursive(matrix, rows, cols, target);
        printResult("RekPier", target, first_rec);

        Position last_rec = findLastRecursive(matrix, rows, cols, target);
        printResult("RekOst", target, last_rec);

        Position first_iter = findFirstIterative(matrix, rows, cols, target);
        printResult("IterPier", target, first_iter);

        Position last_iter = findLastIterative(matrix, rows, cols, target);
        printResult("IterOst", target, last_iter);

        cout << "---" << endl;

        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    return 0;
}