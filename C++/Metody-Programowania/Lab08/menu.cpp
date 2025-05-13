#include "menu.h"
#include <iostream>

using namespace std;

int showMenu() {
    cout << "Wybierz metode generowania liczb pseudolosowych:\n"
        << "1. Liniowa metoda kongruencyjna (LCG)\n"
        << "2. Addytywna metoda kongruencyjna (auto-parametry)\n"
        << "Wybor: ";
    int choice;
    cin >> choice;
    return choice;
}

void getLCGParams(int& a, int& c, int& m, int& seed, int& n) {
    cout << "\nPodaj parametry LCG:\n";
    cout << "Mnoznik (a): "; cin >> a;
    cout << "Przyrost (c): "; cin >> c;
    cout << "Modul (m): "; cin >> m;
    cout << "Ziarno (seed): "; cin >> seed;
    cout << "Liczba liczb (n): "; cin >> n;
}

void getAdditiveParams(int& m, int& n) {
    cout << "\nPodaj parametry metody addytywnej:\n";
    cout << "Modul (m): "; cin >> m;
    cout << "Liczba liczb (n): "; cin >> n;
}