/**
 * METODY PROGRAMOWANIA - LABORATORIUM 12
 * Program do testowania algorytmów sortowania
 *
 * Autor: Oskar Wolny, Arkadiusz Liszka
 *
 */

#include "cSortTablicy.h"
#include <iostream>
using namespace std;

int main() {
    cSortTablicy sorter;
    int wybor;

    cout << "=== PROGRAM DO TESTOWANIA ALGORYTMÓW SORTOWANIA ===" << endl;
    cout << "Wybierz dane do testu:" << endl;
    cout << "1. Dane z polecenia (100, 1000, 1000000)." << endl;
    cout << "2. Wprowadzone recznie." << endl;
    cout << "Wybór: ";
    cin >> wybor;

    try {
        if (wybor == 1) {
            int rozmiary[] = { 1000000, 1000, 100 };
            int ile = sizeof(rozmiary) / sizeof(rozmiary[0]);

            for (int i = 0; i < ile; ++i) {
                cout << "\n" << string(50, '=') << endl;
                cout << "Testowanie dla rozmiaru: " << rozmiary[i] << "..." << endl;
                cout << string(50, '=') << endl;
                sorter.testujDlaRoznychPrzypadkow(rozmiary[i]);
            }
        }
        else if (wybor == 2) {
            cout << "Podaj rozmiar tablicy do testu: ";
            int rozmiar;
            while (!(cin >> rozmiar) || rozmiar <= 0) {
                cout << "Błędna wartość! Podaj liczbę większą od 0: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            cout << "\n" << string(50, '=') << endl;
            cout << "Testowanie dla rozmiaru: " << rozmiar << "..." << endl;
            cout << string(50, '=') << endl;
            sorter.testujDlaRoznychPrzypadkow(rozmiar);
        }
        else {
            cout << "Nieprawidłowy wybór w menu!" << endl;
            return 1;
        }

        cout << "\n" << string(60, '=') << endl;
        cout << "Wszystkie testy zakonczone!" << endl;
        cout << "Sprawdz pliki: wyniki_sortowania_<rozmiar>.txt" << endl;
        cout << string(60, '=') << endl;

    } catch (const exception& e) {
        cerr << "Wystąpił błąd: " << e.what() << endl;
        return 1;
    }

    return 0;
}