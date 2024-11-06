/*******************************************************************************
 * Napisz definicję funkcji zwracających:

sumę elementów tablicy
wartość średnią elementów tablicy
numer indeksu wartości najbliższej do średniej

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int sumaElementow(int tablica[], int rozmiar) {
    int suma = 0;
    for (int i = 0; i < rozmiar; ++i) {
        suma += tablica[i];
    }
    return suma;
}

double sredniaElementow(int tablica[], int rozmiar) {
    if (rozmiar == 0) {
        return 0.0;
    }
    double suma = sumaElementow(tablica, rozmiar);
    return (suma) / rozmiar;
}

int indeksNajblizszyDoSredniej(int tablica[], int rozmiar) {
    double srednia = sredniaElementow(tablica, rozmiar);
    int najblizszyindex = 0;
    //wartość bezwzględna pierwszego elementu tablicy - srednia
    double najmniejszaroznica = abs(tablica[0] - srednia);

    //szuka elementu, którego różnica ze średnią jest najmniejsza
    for (int i = 1; i < rozmiar; i++) {
        double roznica = abs(tablica[i] - srednia);
        if (roznica < najmniejszaroznica) {
            najmniejszaroznica = roznica;
            najblizszyindex = i;
        }
    }
    return najblizszyindex;
}

int main()
{
    
    int tablica[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    
    cout << "Tablica: " << endl;
    
    for (int i = 0; i < rozmiar; i++) {
            cout << tablica[i] << " ";
    }
    cout << endl;

    cout << "Suma elementów tablicy: " << sumaElementow(tablica, rozmiar) << endl;
    
    cout << "Średnia elementów tablicy: " << sredniaElementow(tablica, rozmiar) << endl;
    
    cout << "Indeks najbliższy średniej: " << indeksNajblizszyDoSredniej(tablica, rozmiar) << endl;
    return 0;
}