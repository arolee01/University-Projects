/******************************************************************************

Napisz funkcję otrzymującą jako argumenty wskaźniki do dwóch zmiennych typu int, 
która zwraca jako wartość mniejszą z liczb wskazywanych przez argumenty.

*******************************************************************************/
#include <iostream>

using namespace std;

int wyswietl_mniejsza(const int* a, const int* b) {
    if (*a < *b) {
        return *a;
    } else {
        return *b;
    }
}

int main() {
    int a = 7;
    int b = 10;
    
    cout << "Mniejsza liczba: " << wyswietl_mniejsza(&a, &b) << std::endl;

    return 0;
}
