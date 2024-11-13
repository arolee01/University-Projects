/******************************************************************************

1. wczytuje ze standardowego wejścia trzy liczby: a, b i n.
2. tworzy tablicę o rozmiarze n i wypełnia ją losowymi liczbami całkowitymi z przedziału [a, b]
(zdefiniuj funkcję realizującą tą cześć zadania).
3. wypisuje zawartość tablicy do standardowego wyjścia 
(zdefiniuj funkcję realizującą tą cześć zadania).
4. wyświetla posortowaną tablicę (zdefiniuj funkcję realizującą tą cześć zadania).

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int* stworz_tablice(int a, int b, int n) {
    int* tab = new int[n];
    
    for(int i=0; i<n; i++)
        tab[i] = a + rand() % (b - a + 1);
    return tab;
}

void wyswietl_tablice(int* tab, int n) {
    for (int i = 0; i < n; i++) {
        cout << "[" << tab[i] << "] ";
    }
    cout << endl;
}

void sortuj_tablice(int* tab, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int a, b, n;
    cout << "Podaj liczbę przedziału z lewej strony: ";
    cin >> a;
    cout << "Podaj liczbę przedziału z prawej strony: ";
    cin >> b;
    cout << "Jakiego rozmiaru tablicę stworzyć: ";
    cin >> n;

    int* tab = stworz_tablice(a, b, n);
    cout << "Stworzona tablica z losowymi liczbami: " << endl;
    wyswietl_tablice(tab, n);
    
    sortuj_tablice(tab, n);
    cout << "Posortowana tablica: " << endl;
    wyswietl_tablice(tab, n);
    
    return 0;
}