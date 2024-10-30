#include <iostream>

using namespace std;

int sumowanie(int x) {
    int wynik = 0;
    do {
        wynik = wynik + x % 10;
        x = x / 10;
    } while (x != 0);
    return wynik;
}

int main()
{
    int x = 0;
    cout << "Podaj liczbę: ";
    cin >> x;
    
    
    cout << "Suma cyfr podanej liczby, to: " << sumowanie(x);
    return 0;
}