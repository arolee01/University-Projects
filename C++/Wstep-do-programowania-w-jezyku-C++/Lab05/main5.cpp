/******************************************************************************

Napisz funkcję, która dostaje jako argumenty dwuwymiarową prostokątną tablicę
tablic tab1 o wymiarach n × m i elementach typu int oraz jej wymiary, i zwraca
jako wartość wskaźnik do nowo utworzonej dwuwymiarowej tablicy tablic tab2
o wymiarach m × n zawierającej transponowaną macierz przechowywaną
w tablicy tab1 (czyli dla dowolnych k i j zachodzi tab1[k][j] = tab2[j][k].

*******************************************************************************/

#include <iostream>

using namespace std;

int** transponowanieMacierzy(int** tab1, int n, int m) {
    int** tab2 = new int*[m];
    for (int i = 0; i < m; i++) {
        tab2[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tab2[j][i] = tab1[i][j];
        }
    }

    return tab2; 
}

void wyswietlanieTablicy(int **tab, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n = 3, m = 4;

    int** tab1 = new int*[n];
    for (int i = 0; i < n; i++) {
        tab1[i] = new int[m];
    }

    int wartosc = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tab1[i][j] = wartosc++;
        }
    }
    
    cout << "Macierz tab1: " << endl;
    wyswietlanieTablicy(tab1, n, m);
    
    int** tab2 = transponowanieMacierzy(tab1, n, m);
    
    cout << "Macierz tab2: " << endl;
    wyswietlanieTablicy(tab2, m, n); // Zamiana n i m miejscami

    // Zwalnianie pamięci
    for (int i = 0; i < n; i++) {
        delete[] tab1[i];
    }
    delete[] tab1;

    for (int i = 0; i < m; i++) {
        delete[] tab2[i];
    }
    delete[] tab2;

    return 0;
}