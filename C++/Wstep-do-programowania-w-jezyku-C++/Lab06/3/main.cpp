/******************************************************************************

Napisz funkcję, która dostaje w argumentach jednowymiarową tablicę liczb
całkowitych tab, jej rozmiar oraz ścieżkę dostępu do pliku tekstowego,
i dopisuje w kolejnych wierszach na końcu otrzymanego pliku wartości kolejnych
elementów tablicy tab.

*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

void dopisywanie(int* tab, size_t rozmiar, string& sciezkaPliku) {
    
    ofstream plik(sciezkaPliku, ios::app);
    if (!plik) {
        cout <<"Nie mogę otworzyć takiego pliku!" << endl;
    }
    
    for (size_t i = 0; i < rozmiar; ++i) {
        plik << tab[i] << endl;
    }

    plik.close();
}

int main() {
    
    int tab[] = {1, 2, 3, 4, 5};
    size_t rozmiar = sizeof(tab) / sizeof(tab[0]);
    string sciezkaPliku = "plik.txt";

    dopisywanie(tab, rozmiar, sciezkaPliku);

    cout << "Dane zostały dopisane do pliku." << endl;

    return 0;
}