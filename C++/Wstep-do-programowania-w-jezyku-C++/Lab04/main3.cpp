/******************************************************************************

Napisz funkcję (do każdego punktu osobna funkcja), która otrzymuje dwa argumenty: 
dodatnią liczbę całkowitą n oraz n-elementową tablicę tab o elementach typu int i:

zwraca największą wartość przechowywaną w tablicy tab,
zwraca najmniejszą wartość przechowywaną w tablicy tab,
zwraca indeks elementu tablicy tab o największej wartości,
zwraca indeks elementu tablicy tab o najmniejszej wartości,
zwraca największą spośród wartości bezwzględnych elementów przechowywanych w tablicy tab,
zwraca indeks elementu tablicy tab o największej wartości bezwzględnej.

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int najmniejszaWartosc(int tab[], int n) {
    
    int min;
	min = tab[0];
	
	for(int i = 1; i < n; i++) {
	    if(min > tab[i])
			min = tab[i];
	}
	
    return min;
}

int najwiekszaWartosc(int tab[], int n) {
     
    int max;
	max = tab[0];
	
	for(int i = 1; i < n; i++) {
	    if(max < tab[i]) {
	        max = tab[i];
	    }
	}
	
    return max;
}

int indeksNajwiekszej(int tab[], int n) {
    int max = tab[0];
    int indeks = 0;
    for (int i = 1; i < n; i++) {
        if (tab[i] > max) {
            max = tab[i];
            indeks = i;
        }
    }
    return indeks;
}

int indeksNajmniejszej(int tab[], int n) {
    int min = tab[0];
    int indeks = 0;
    for (int i = 1; i < n; i++) {
        if (tab[i] < min) {
            min = tab[i];
            indeks = i;
        }
    }
    return indeks;
}

int najwiekszaBezwzgledna(int tab[], int n) {
    int maxAbs = abs(tab[0]);
    for (int i = 1; i < n; i++) {
        if (abs(tab[i]) > maxAbs) {
            maxAbs = abs(tab[i]);
        }
    }
    return maxAbs;
}

int indeksNajwiekszejBezwzglednej(int tab[], int n) {
    int maxAbs = abs(tab[0]);
    int indeks = 0;
    for (int i = 1; i < n; i++) {
        if (abs(tab[i]) > maxAbs) {
            maxAbs = abs(tab[i]);
            indeks = i;
        }
    }
    return indeks;
}


int main()
{
    int n;
    do {
        cout << "Podaj dodatnią liczbę całkowitą n: " << endl;
        cin >> n;
    } while (n<1);
    
    int tab[n];
    
    cout << "Podaj " << n << " elementów do tablicy:" << endl;
    for (int i=0; i<n; i++) {
        cout << "Element " << i+1 << ": ";
        cin >> tab[i];
    }

    cout << "Tablica:" << endl;
    for (int i=0; i<n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    cout << "Największa wartość w tablicy: " << najwiekszaWartosc(tab, n) << endl;
    cout << "Najmniejsza wartość w tablicy: " << najmniejszaWartosc(tab, n) << endl;
    cout << "Indeks największej wartości w tablicy: " << indeksNajwiekszej(tab, n) << endl;
    cout << "Indeks najmniejszej wartości w tablicy: " << indeksNajmniejszej(tab, n) << endl;
    cout << "Największa wartość bezwględna w tablicy: " << najwiekszaBezwzgledna(tab, n) << endl;
    cout << "Indeks największej wartości bezwzględnej w tablicy: " << indeksNajwiekszejBezwzglednej(tab, n) << endl;

    return 0;
}