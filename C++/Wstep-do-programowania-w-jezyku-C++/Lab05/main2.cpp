/******************************************************************************

Napisz funkcję, której argumentami są dwa wskaźniki do stałych typu int,
zaś zwracaną wartością jest suma wartości zmiennych wskazywanych przez argumenty.

*******************************************************************************/
#include <iostream>

using namespace std;

int suma(const int* a, const int* b) {
    return *a + *b;
}

int main() {
    int a = 5;
    int b = 10;
    
    cout << "Suma: " << suma(&a, &b) << endl;

    return 0;
}
