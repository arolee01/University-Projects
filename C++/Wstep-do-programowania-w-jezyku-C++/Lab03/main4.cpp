/******************************************************************************

Napisz program który losuje liczbę od 1 do N i prosi użytkownika o odgadnięcie jej. 
Po każdej próbie użytkownik powinien być nakierowany na właściwą odpowiedź przez wyświetlenie 
informacji „ciepło”, „zimno”, „gorąco”. Określ w programie po ilu próbach użytkownik powinien 
odgadnąć właściwą odpowiedź? Jeśli użytkownik odniesie sukces w mniejszej liczbie kroków, 
poinformuj go o wygranej, w przeciwnym wypadku o przegranej.

Program ma być napisany z podziałem na funkcje, liczbę N podaje użytkownik w trakcie 
działania programu.

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int losowanieLiczby(int n) {
    int wylosowana = rand() % n + 1;
    return wylosowana;
}

int iloscProb(int n) {
    int iloscprob;
    if (n<=5) {
        iloscprob = 2;
    } else if (n>5 and n<=10) {
        iloscprob = 3;
    } else if (n>10 and n<=20) {
        iloscprob = 5;
    } else {
        iloscprob = 10;
    }
    
    return iloscprob;
}

void zgadywanie(int wylosowanaliczba, int iloscprob) {
    int podana;
    int proba = 1;
    while(proba <= iloscprob) {
        cout << "Podaj " << proba << ". liczbę:" << endl;
        cin >> podana;
        proba++;
        if (podana==wylosowanaliczba) {
            cout << "Brawo! Zgadłeś wylosowaną liczbę." << endl;
            return;
        } else {
            if ((abs(wylosowanaliczba-podana))<=5) {
                if ((abs(wylosowanaliczba-podana))<=3) {
                    cout << "Gorąco!" << endl;
                } else {
                    cout << "Ciepło!" << endl;   
                }
            } else {
                cout << "Zimno!" << endl;
            }
        }
    }
    cout << "Niestety, nie udało Ci się zgadnąć liczby. Twoją liczbą było: " << wylosowanaliczba;
} 


int main()
{
    srand(time(NULL)); // bez tej linijki, wylosowana liczba jest ciągle taka sama
    int n;
    cout << "Podaj maksymalną liczbę przedziału z prawej strony: " << endl;
    cin >> n;
    do {
        if (n<=1) {
            cout << "Nie możesz podać takiej wartości, podaj większą liczbę: " << endl;
            cin >> n;
        }
    } while (n<=1);
    
    
    int wylosowana = losowanieLiczby(n);
    int iloscprob = iloscProb(n);
    
    cout << "Liczba z przedziału <1," << n << "> została wylosowana!" << endl;
    cout << "Masz " << iloscprob;
    
    if (iloscprob==2 or iloscprob ==3) {
        cout << " próby";
    } else {
        cout << " prób";
    }
    cout << " na zgadnięcie wylosowanej liczby. " << endl;
    
    zgadywanie(wylosowana, iloscprob);
    
    return 0;
}