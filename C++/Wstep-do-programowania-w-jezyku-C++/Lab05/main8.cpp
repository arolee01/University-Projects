/******************************************************************************

Napisz funkcję, która dostaje jako argument wskaźnik do jednowymiarowej
dynamicznej tablicy o elementach typu double i zwalnia pamięć zajmowaną
przez przekazaną w argumencie tablicę.

*******************************************************************************/
#include <iostream>

void zwolnijTablice(double* tablica) {
        delete[] tablica;
}

int main() {
    double* tab = new double[10];

    zwolnijTablice(tab);

    return 0;
}
