/******************************************************************************

Napisz funkcję, która dostaje jako argumenty nazwę pliku, dwuwymiarową
tablicę tablic o elementach typu int oraz wymiary tablicy i zapisuje
binarnie zawartość tablicy do podanego pliku.

*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

void zapiszBinarnie(const char* nazwaPliku, int** tablica, int wiersze, int kolumny) {
    ofstream plik(nazwaPliku, ios::binary);
    if (!plik) {
        cout << "Nie można otworzyć pliku: " << nazwaPliku << endl;
        return;
    }

    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            plik.write((char*)&tablica[i][j], 4);
        }
    }

    plik.close();
    cout << "Tablica została zapisana do pliku: " << nazwaPliku << endl;
}

int main() {
    int wiersze = 3, kolumny = 4;

    int** tablica = new int*[wiersze];
    for (int i = 0; i < wiersze; ++i) {
        tablica[i] = new int[kolumny];
    }

    int liczba = 1;
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            tablica[i][j] = liczba++;
        }
    }

    zapiszBinarnie("tablica.bin", tablica, wiersze, kolumny);

    for (int i = 0; i < wiersze; ++i) {
        delete[] tablica[i];
    }
    delete[] tablica;

    return 0;
}