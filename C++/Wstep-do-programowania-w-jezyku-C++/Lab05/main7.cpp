/******************************************************************************

Napisz funkcję, która dostaje w argumentach dodatnią liczbę całkowitą
n oraz n-elementową tablicę liczb całkowitych tab1 o elementach typu int,
i przepisuje do nowo utworzonej tablicy tab2 elementy tablicy tab1 o wartości
różnej od zera. Rozmiar nowo tworzonej tablicy tab2 powinien być równy liczbie
niezerowych elementów tablicy tab1. Jako wartość funkcja powinna zwrócić
wskaźnik na pierwszy element tablicy tab2.

*******************************************************************************/
#include <iostream>

using namespace std;

int* przepiszRozneOdZera(int tab1[], int n) {
    int RozneOdZera = 0;
    
    for (int i = 0; i < n; i++) {
        if (tab1[i] != 0) {
            RozneOdZera++;
        }
    }
    
    int* tab2 = new int[RozneOdZera];
    
    int j = 0;
    for (int i = 0; i<n; i++) {
        if (tab1[i] != 0) {
            tab2[j] = tab1[i];
            j++;
        }
    }
    for (int i = 0; i < RozneOdZera; i++) {
        cout << tab2[i] << " ";
    }
    
    return tab2;
}

int main()
{
    int n = 8;
    int tab1[] = {8, -2, 0, 7, 3, -5, 8, 9};
    
    for (int i = 0; i < 8; i++) {
        cout << tab1[i] << " ";
    }
    cout << endl;
    
    int* tab2 = przepiszRozneOdZera(tab1, n);
    

    cout << endl;
    
    delete[] tab2;
    
    return 0;
}