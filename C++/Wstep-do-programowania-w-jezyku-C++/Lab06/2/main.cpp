/******************************************************************************

Napisz funkcję, która dostaje jako argumenty ścieżki dostępu do dwóch plików
i dopisuje zawartość pierwszego pliku na koniec drugiego pliku.

*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

void dopiszZawartosc(string& pierwszyPlik, string& drugiPlik) {
    ifstream plikWejscia(pierwszyPlik);
    if (!plikWejscia) {
        cout <<"Nie mogę otworzyć takiego pliku!" <<endl;
    }
    
    ofstream plikWyjscia(drugiPlik, ios::app);
    if (!plikWyjscia) {
        cout <<"Nie mogę otworzyć takiego pliku!" <<endl;
    }
    
    string linijka;
    while (getline(plikWejscia, linijka)) {
        plikWyjscia << linijka << endl;
    }
    
}

int main()
{
    string pierwszyPlik = "pierwszy.txt";
    string drugiPlik = "drugi.txt";
    
    dopiszZawartosc(pierwszyPlik, drugiPlik);

    
    return 0;
}