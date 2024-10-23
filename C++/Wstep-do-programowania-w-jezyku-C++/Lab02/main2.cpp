#include <iostream>

using namespace std;

int main() {
    int n;
    do {
        cout<<"Podaj nieujemną liczbę całkowitą n (maksymalnie 20): "<<endl; 
        cin >> n;
    } while (n < 0 or n > 20); //dla long long wartość silni może być maksymalnie 20!
    
    unsigned long long suma = 0;
    unsigned long long silnia = 1;

    cout << "0! = 1" << endl;
    
    for (int i = 1; i <= n; ++i) {
        silnia *= i;  // obliczanie silni
        cout << i << "! = " << silnia << endl;
        suma += silnia; // dodawanie do sumy
    }

    suma += 1; // 0! = 1
    cout << "Suma silni od 0! do " << n << "! wynosi: " << suma << endl;

    return 0;
}
