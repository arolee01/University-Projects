/******************************************************************************

Napisz funkcję, która dostaje jako argumenty ścieżki dostępu do dwóch plików i 
przepisuje zawartość pierwszego pliku do drugiego pliku 
(stara zawartość drugiego pliku ma zostać skasowana).
*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

void przepiszZawartosc(string& pierwszyPlik, string& drugiPlik) {
    ifstream plikWejscia(pierwszyPlik);
    if (!plikWejscia) {
        cout <<"Nie mogę otworzyć takiego pliku!" <<endl;
    }
    
    ofstream plikWyjscia(drugiPlik);
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
    
    przepiszZawartosc(pierwszyPlik, drugiPlik);

    
    return 0;
}