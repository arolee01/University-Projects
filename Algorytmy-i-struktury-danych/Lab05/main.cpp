/******************************************************************************

Projektowanie algorytmów

Zadanie 1:

Proszę podać i zaimplementować algorytm zwracający sumę wszystkich dzielników właściwych podanej liczby naturalnej n. Algorytm należy zaimplementować w postaci funkcji: int divSum(int n) oraz przetestować poprawność jego działania dla kilku różnych liczb.

Szablon rozwiązania:

//Zadanie 1
int divSum(int n){
 
}

int main(int argc, char** argv) {

//Zadanie 1 - test
cout<<endl<<"Zadanie 1 - test"<<endl;
cout<<endl<<"suma dzelnikow 15 = "<<divSum(15);  //oczekiwany wynik: 9
cout<<endl<<"suma dzelnikow 17 = "<<divSum(17);  //oczekiwany wynik: 1
//...
//lub
{
    int liczba;
    cin>>n;
    cout<<endl<<"suma dzielnikow "<<n<<" = "<<divSum( n );
}
 return 0;
}

Zadanie 2:

Liczba doskonała jest równa sumie swoich dzielników właściwych.

Przykład:

6 = 1 + 2 +3

28 = 1 + 2 + 4 + 7 + 14

Proszę podać i zaimplementować algorytm sprawdzający czy podana liczba n jest liczbą doskonałą. Algorytm należy zaimplementować w postaci funkcji: bool isPerfect(int n) oraz przetestować poprawność jego działania dla kilku różnych liczb.

Szablon rozwiązania:

//Zadanie 2
bool isPerfect(int n){
}

do main():

//Zadanie 2 - test
cout<<endl<<"Zadanie 2 - test"<<endl;
cout<<endl<<"Liczba: 6 "<<isPerfect(6);  //oczekiwany wynik: true
cout<<endl<<"Liczba: 12 "<<isPerfect(12);  //oczekiwany wynik: false
//.....
//lub
{
    int n;
    cin>>n;
    cout<<endl<<"LIczba: "<<n<<isPerfect( n );
}

Inne liczby doskonałe: 496, 8128, 33550336, ...

Zadanie 3:

Proszę podać i zaimplementować algorytm umożliwiający znalezienie i wyświetlenie wszystkich liczb doskonałych w podanym zakresie <1, n>. Algorytm należy zaimplementować w postaci funkcji: void allPerfect(int n) oraz przetestować poprawność jego działania dla określonego zakresu.

Szablon rozwiązania:

//Zadanie 3
void allPerfect(int n){
}

do main():

//Zadanie 3 - test
cout<<endl<<"Zadanie 3 - test"<<endl;
cout<<"Liczby doskonale w zakresie: 1 - 9000 "<<endl;
allPerfect(9000); //oczekiwany wynik: 6, 28, 496, 8128
//lub
{
    int n;
    cin>>n;
    cout<<"Liczby doskonale w zakresie 1 - :<<n<<endl;
    allPerfect ( n );

}

Zadanie 4:

Liczby naturalne n, m są liczbami zaprzyjaźnionymi jeśli n jest równe sumie dzielników właściwych m i m jest równe sumie dzielników właściwych n.

Przykład:

n = 220 = 1 + 2 + 4 + 71 + 142 (1, 2, 4, 71, 142 są dzielnikami 284)

m = 284 = 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110 (gdzie 1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110 są dzielnikami 220)

Proszę podać i zaimplementować algorytm sprawdzający czy dwie podane liczby naturalne są liczbami zaprzyjaźnionymi. Algorytm należy zaimplementować w postaci funkcji: bool areAmicable(int n, int m) oraz przetestować poprawność jego działania dla kilku różnych par liczb.

Inne pary liczb zaprzyjaźnionych: 1184 i 1210;  2620 i 2924; 5020 i 5564;  6232 i 6368; 10744 i 10856; 12285 i 14595; 17296 i 18416; 63020 i 76084; 66928 i 66992

Szablon rozwiązania:

//Zadanie 4
bool areAmicable(int n, int m){
}

do main():

//Zadanie 4 - test
cout<<endl<<"Zadanie 4 - test"<<endl;
cout<<"Liczby 220 i 284 "<<areAmicable(220, 284);
//lub
{
    int n, m;
    cin>>n>>m;
    cout<<"Liczby: "<<n<<" i "<<m<<" "<<areAmicable(n, m);
}

Zadanie 5:

Proszę podaj i zaimplementować algorytm umożliwiający znalezienie i wyświetlenie wszystkich par liczb zaprzyjaźnionych w podanym zakresie <1, n>. Algorytm należy zaimplementować w postaci funkcji: void allAmicable(int n) oraz przetestować poprawność jego działania dla określonego zakresu.

Szablon rozwiązania:

//Zadanie 5
void allAmicable(int n ){
}


do main():

cout<<endl<<"Zadanie 5 - test"<<endl;
cout<<"Liczby zaprzyjaźnione w zakresie: 1 - 3000 "<<endl;
allAmicable(3000); //oczekiwany wynik: 220 i 284; 1184 i 1210; 2620 i 2924

//lub
{
    int n;
    cin>>n;
    cout<<"Liczby zaprzyjaznione w zakresie 1 - :<<n<<endl;
    allAmicable( n );
}
*******************************************************************************/
#include <iostream>

using namespace std;

// Zadanie 1
int divSum(int n) {
    // Jeśli liczba jest mniejsza lub równa 1
    // to suma dzielników właściwych wynosi 0
    if(n <= 1) return 0;
    
    int suma = 0;
    
    // Sprawdzanie liczb od 1 do n/2
    // Jeśli i dzieli n bez reszty do dodajemy do sumy
    for (int i=1; i <= (n/2); i++) {
        if (n % i == 0) {
            suma += i;
        }
    }
    return suma;
}
// Zadanie 2 
bool isPerfect(int n){
    // Liczba doskonała musi być równa sumie swoich dzielników
    // Liczby poniżej 1 nie są doskonałe
    if (n <= 1) return false;
    
    return (divSum(n) == n);
}

// Zadanie 3
// Podawanie wszystkich liczb z zakresu <1;n>
void allPerfect(int n) {
    for (int i=1; i<=n; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Zadanie 4
// Liczby zaprzyjaźnione jeśli n jest równe sumie dzielników
// właściwych m i m jest równe sumie dzielnikó właściwych nie
bool areAmicable(int n, int m){
    if (divSum(n) == m && divSum(m) == n) {
        return true;
    }
    return false;
}

// Zadanie 5
// Podaje liczby zaprzyjaźnione z zakresu <1;n>
void allAmicable(int n){
    for (int i=2; i<=n; i++) {
        int m = divSum(i);
        
        if (m>i && m<=n) {
            if (divSum(m) == i) {
                cout << i << " i "<< m <<"; ";
            }
        }
    }
    cout << endl;
    
}

int main(int argc, char** argv) {
    
    cout << "-------------------" <<endl;
    cout << "Zadanie 1 - test" <<endl;
    cout << "Suma dzelnikow 15 = " << divSum(15) << endl;  //oczekiwany wynik: 9
    cout << "Suma dzelnikow 17 = " << divSum(17) << endl;  //oczekiwany wynik: 1
    cout << "-------------------" <<endl;
    cout << "Zadanie 2 - test" << endl;
    cout << "Liczba 6: " << isPerfect(6) << endl;  //oczekiwany wynik: true
    cout << "Liczba 12: " << isPerfect(12) << endl;  //oczekiwany wynik: false
    cout << "-------------------" <<endl;
    cout << "Zadanie 3 - test" << endl;
    cout << "Liczby doskonale w zakresie: 1 - 9000 " << endl;
    allPerfect(9000); //oczekiwany wynik: 6, 28, 496, 8128
    cout << "-------------------" << endl;
    cout << "Zadanie 4 - test" << endl;
    cout << "Liczby 220 i 284 " << ": "<< areAmicable(220, 284) <<endl;
    cout << "Liczby 1 i 2 " << ": "<< areAmicable(1, 2) <<endl;
    cout << "-------------------" << endl;
    cout << "Zadanie 5 - test" << endl;
    cout << "Liczby zaprzyjaźnione w zakresie: 1 - 3000 " <<  endl;
    allAmicable(3000); //oczekiwany wynik: 220 i 284; 1184 i 1210; 2620 i 2924
    
    return 0;
}