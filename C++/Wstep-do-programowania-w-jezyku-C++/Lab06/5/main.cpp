/******************************************************************************

Napisz funkcję, która dostaje jako argumenty nazwę pliku, dwuwymiarową tablicę
tablic o elementach typu int oraz wymiary tablicy i wczytuje binarnie zawartość
pliku do tablicy.
*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

void binarnieZPliku(const char* nazwaPliku, int** tablica, int wiersze, int kolumny) {
    ifstream plik(nazwaPliku, ios::binary);
    
    if (!plik) {
        cout << "Nie można otworzyć pliku: " << nazwaPliku << endl;
        return;
    }

    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            plik.read((char*)&tablica[i][j], sizeof(int));  
        }
    }

    plik.close();
    cout << "Tablica została wczytana z pliku: " << nazwaPliku << endl;
}

int main() {
    int wiersze = 3, kolumny = 4;

    int** tablica = new int*[wiersze];
    for (int i = 0; i < wiersze; ++i) {
        tablica[i] = new int[kolumny];
    }

    binarnieZPliku("tablica.bin", tablica, wiersze, kolumny);

    cout << "Wczytana tablica:" << endl;
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            cout << tablica[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < wiersze; ++i) {
        delete[] tablica[i];
    }
    delete[] tablica;

    return 0;
}
