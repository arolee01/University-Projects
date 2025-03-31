#include <iostream>
#include <fstream>
using namespace std;

/*
 * Generuje wszystkie k-elementowe podzbiory zbioru {1, 2, ..., n} w porządku leksykograficznym i zapisuje je do pliku.
 * @param n - liczba elementów w zbiorze.
 * @param k - liczba elementów w podzbiorze (k < n).
 */
void f_generateKSubsets(int n, int k) {
    ofstream outFile("lab3_2d_2.txt");
    if (!outFile) {
        cerr << "Cannot open file." << endl;
        return;
    }

    int* A = new int[k + 1];
    for (int i = 1; i <= k; i++) {
        A[i] = i; 
    }

    int p = k;
    while (p >= 1) {
        for (int i = 1; i <= k; i++) {
            outFile << A[i] << " ";
        }
        outFile << endl;

        if (A[k] == n) {
            p--;
        }
        else {
            p = k;
        }

        if (p >= 1) {
            for (int i = k; i >= p; i--) {
                A[i] = A[p] + (i - p) + 1;
            }
        }
    }

    delete[] A;
    outFile.close();
}

int main() {
    int n, k;
    cout << "Enter n and k (k < n): ";
    cin >> n >> k;
    if (k >= n) {
        cout << "k must be less than n." << endl;
        return 1;
    }
    f_generateKSubsets(n, k);
    cout << "The subsets were saved to a file." << endl;
    return 0;
}