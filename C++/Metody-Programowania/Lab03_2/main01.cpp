#include <iostream>
#include <fstream>
using namespace std;

/*
 * Generuje wszystkie podzbiory zbioru n-elementowego w kolejności Graya i zapisuje je do pliku.
 * @param n - liczba elementów w zbiorze.
 */
void f_generateSubsets(int n) {
    ofstream outputFile("lab3_1d.txt"); // Otwiera plik wyjściowy do zapisu
    if (!outputFile) {
        cerr << "Cannot open file." << endl;
        return;
    }

    int* B = new int[n + 1](); // Tablica reprezentująca aktualny podzbiór w postaci binarnej (z dodatkowym miejscem na indeksowanie od 1)
    int i = 0;                 // Licznik iteracji
    int p, j;

    do {
        // Wypisanie aktualnego stanu tablicy B (aktualny podzbiór) do pliku
        for (int k = 1; k <= n; k++) {
            outputFile << B[k];
        }
        outputFile << endl;

        // Przejście do kolejnej iteracji
        i++;         
        p = 1;
        j = i;

        // Obliczanie pozycji najniższego zera w zapisie binarnym, co określa który bit zmienić w kodzie Graya
        while (j % 2 == 0) {
            j /= 2;
            p++;
        }

        // Zamiana bitu na pozycji p — przełącza 0 na 1, 1 na 0
        // Tylko jeden bit zmienia się między kolejnymi elementami w kodzie Graya
        if (p <= n) {
            B[p] = 1 - B[p];
        }
    } while (p <= n);

    // Zwolnienie pamięci
    delete[] B;
    // Zamknięcie pliku
    outputFile.close();   
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    f_generateSubsets(n);
    cout << "The subsets were saved to a file." << endl;
    return 0;
}
