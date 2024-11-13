/******************************************************************************

Napisz funkcję otrzymującą jako argumenty referencje do dwóch zmiennych typu int,
która zamienia ze sobą wartości zmiennych, do których referencje dostaliśmy w argumentach.

*******************************************************************************/
#include <iostream>

using namespace std;

void zamiana_wartosci(int& a, int& b) {
    int temp = a;  
    a = b;         
    b = temp;      
}

int main() {
    int a = 5;
    int b = 10;
    
    cout << "Przed zamianą: a = " << a << ", b = " << b << endl;
    zamiana_wartosci(a, b);
    cout << "Po zamianie: a = " << a << ", b = " << b << endl;

    return 0;
}
