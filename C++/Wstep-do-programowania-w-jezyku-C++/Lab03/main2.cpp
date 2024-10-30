#include <iostream>

using namespace std;

unsigned long long silniaRekurencyjnie (int x) {
    if (x==0) {
        return 1;
    }
    else {
        return x*silniaRekurencyjnie(x-1);    
    }
}

unsigned long long silniaIteracyjnie (int x) {
    int i=1;
    long long silnia = 1;
    while(i<=x) {
        silnia=silnia*i;
        i++;
    }
    return silnia;
}


void sumaSilni(int x, int y) {
    
    switch(y) {
        case 1:
            cout << "Wynik silni obliczonej rekurencyjnie wynosi: " << silniaRekurencyjnie(x) << endl;
        break;
        case 2:
            cout << "Wynik silni obliczonej iteracyjnie wynosi: " << silniaIteracyjnie(x) << endl;
        break;
}
    
    
    unsigned long long suma = 0;
    unsigned long long silnia = 1;

    cout << "0! = 1" << endl;
    
    for (int i = 1; i <= x; ++i) {
        silnia *= i;  // obliczanie silni
        cout << i << "! = " << silnia << endl;
        suma += silnia; // dodawanie do sumy
    }

    suma += 1; // 0! = 1
    cout << "Suma silni od 0! do " << x << "! wynosi: " << suma << endl;
}

int main() {
    int n=0;
    int wybor=0;
    do {
        cout << "Podaj n dla jakiego mam obliczyć silnię: ";
        cin >> n;        
    } while (n<0);

    cout << "Wybierz, którą metodą mam obliczyć silnię (1 - Rekurencyjnie, 2 - Iteracyjnie): ";
    cin >> wybor;
    
    sumaSilni(n, wybor);

    return 0;
}