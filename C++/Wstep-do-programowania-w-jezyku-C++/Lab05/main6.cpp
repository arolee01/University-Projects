/******************************************************************************
 
 Napisz funkcję, która dostaje w argumentach dodatnią liczbę całkowitą n oraz
 n-elementową tablicę liczb całkowitych tab1 o elementach typu int, i przepisuje
 do nowo utworzonej tablicy tab2 elementy tablicy tab1 o wartości różnej od zera.
 Rozmiar nowo tworzonej tablicy tab2 powinien być równy liczbie niezerowych
 elementów tablicy tab1. Jako wartość funkcja powinna zwrócić wskaźnik
 na pierwszy element tablicy tab2.
 
*******************************************************************************/
#include <iostream>

using namespace std;

int* kopiowanieNiezerowychElementów(int* tab1, int n) {
    int niezerowe = 0;
    for (int i = 0; i < n; i++) {
        if (tab1[i] != 0) {
            niezerowe++;
        }
    }
    
    int* tab2 = new int[niezerowe];
    
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (tab1[i] != 0) {
            tab2[index] = tab1[i];
            index++;
        }
    }
    return tab2;
}


void wyswietlanieTablicy(int *tab, int n) {
    for (int i = 0; i < n; i++) {
            cout << tab[i] << " ";
        cout << endl;
    }
}

int main() {
    
    int n = 6;
    
    int tab1[] = {2, 7, -4, 0,  1, 0};
    
    cout << "Tablica tab1: " << endl;
    wyswietlanieTablicy(tab1, n);
    
    int niezerowe = 0;
    for (int i = 0; i < n; i++) {
        if (tab1[i] != 0) {
            niezerowe++;
        }
    }
    
    int* tab2 = kopiowanieNiezerowychElementów(tab1, niezerowe);
    
    cout << "Tablica tab2: " << endl;
    wyswietlanieTablicy(tab2, n);

    return 0;
}