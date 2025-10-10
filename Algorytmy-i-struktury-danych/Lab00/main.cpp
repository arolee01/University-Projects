/******************************************************************************

Zadanie 1:

Dla n liczb naturalnych, przechowywanych w tablicy S, 
proszę zaimplementować algorytm wyszukiwania liniowego dla problemu stwierdzenia
czy szukana wartość x występuje w tablicy. Algorytm należy zaimplementować w 
postaci funkcji: int linearSearch1(int* S, int n, int x) zwracającej indeks 
pierwszego wystąpienia x w S lub -1 jeśli x nie występuje w S. 
Proszę przetestować poprawność działania algorytmu (należy sprawdzić działanie 
algorytmu co najmniej dla wartości pierwszej, ostatniej, dowolnej innej oraz dla 
przypadku braku x).

Szablon rozwiązania:

//Zadanie 1

void print(int* S, int n){              //wyświetla dane na monitorze
}

int linearSearch1(int* S, int n, int x){
}

//Zadanie 1 - test
{
    int n = 20;        //przykładowy rozmiar
    int *S = new int[n]{};
    int x;
    print(S,n);
    //wczytanie/ustawienie x dla przypadku 1 - x na pozycji 0
    cout<<linearSearch1(S,n,x);  //x na pozycji 0
    //...
}

Zadanie 2:

Dla n liczb naturalnych, przechowywanych w tablicy S, proszę zaimplementować 
algorytm wyszukiwania binarnego dla problemu stwierdzenia czy szukana wartość
x występuje w tablicy. Algorytm należy zaimplementować w postaci funkcji: 
int binarySearch1(int* S, int n, int x) zwracającej indeks wystąpienia x 
w S lub -1 jeśli x nie występuje w S. Proszę przetestować poprawność działania 
algorytmu (należy uwzględnić przypadek znalezienia x w pierwszym kroku,
ostatnim, dowolnych i braku x w S).

Szablon rozwiązania:


//Zadanie 2

int binarySearch1(int* S, int n, int x){   //wersja iteracyjna
}

//Zadanie 2 - test
{
    int n = 20;        //przykładowy rozmiar
    int *S new int[n]{};
    int x;
    print(S,n);
    //wczytanie/ustawienie x dla przypadku 1 - x znalezione w pierwszym kroku (pozycja ...)

    cout<<binarySearch1(S,n,x);  //x na pozycji .....
    //...
}

Zadanie 3:

Proszę zaimplementować funkcje: int linearSearch2(int* S, int n, int x) i 
int binarySearch2(int* S, int n, int x) modyfikujące odpowiednio funkcje z 
zadania 1 i 2 w taki sposób aby zliczały i zwracały liczbę powtórzeń operacji 
dominującej (zamiast zwracania pozycji wystąpienia x i -1). Proszę przetestować 
poprawność działania algorytmów według schematów dla zadań 1 i 2.

Szablon rozwiązania:

//Zadanie 3

int linearSearch2(int* S, int n, int x){

}

int binarySearch2(int* S, int n, int x){   //wersja iteracyjna
}

Zadanie 4:

Wykorzystując obydwie z funkcji z zadania 3 proszę przeprowadzić eksperyment,
który pozwoli ocenić jak liczba danych wpływa na liczbę kroków oraz odnieść 
uzyskany wynik do złożoności tych algorytmów.

Wykonanie eksperymentu wymaga:

    stopniowego zwiększania rozmiaru danych w określonym przedziale 
    (np. 10 - 100000) oraz dla każdego rozmiaru danych:

    wygenerowania losowego zbioru danych* (posortowanego) oraz

    wielokrotnego powtórzenia próby (np. 100 razy) i wyliczenia i wyświetlenia 
    średniej liczby kroków

pojedyncza próba powinna obejmować:
    wygenerowanie losowej wartości x,
    wykonanie wyszukiwania,
    zwrócenia uzyskanej w nim liczby kroków

Do generacji liczb losowych można użyć następujących funkcji:

    srand(time(NULL)) – uruchamia generator, wywołanie raz w main()
    rand()%n – zwraca liczbę z zakresu 0-n
    Użycie w/w funkcji wymaga dołączenia bibliotek: cstdlib, ctime

Przykładowa funkcja generująca dane w porządku niemalejącym:

void initSorted(int* S, int n) {              //inicjalizuje tablicę S losowymi liczba posortowanymi niemalejąco
    S[0] = rand()%10;
    for(int i = 1; i < n; i++)
       S[i] = S[i-1]+ rand()%10;
}


Zadanie 5:

Dla n losowych liczb naturalnych, przechowywanych w tablicy S, proszę 
zaimplementować algorytm wyszukiwania interpolacyjnego dla problemu stwierdzenia
czy szukana wartość x występuje w tablicy. Algorytm należy zaimplementować w 
postaci funkcji: int interpolationSearch1(int* S, int n, int x) zwracającej indeks
wystąpienia x w S lub -1 jeśli x nie występuje w S. Proszę przetestować poprawność
działania algorytmów według schematu dla zadania 2.

Szablon rozwiązania:

//Zadanie 5

int interpolationSearch1(int* S, int n, int x) { //wersja iteracyjna

}

Zadanie 6:

Proszę zaimplementować funkcję: int interpolationSearch2(int* S, int n, int x)
modyfikującą funkcję int interpolationSearch1(int* S, int n, int x) w taki sposób
aby zliczała i zwracała liczbę powtórzeń operacji dominującej. Następnie, wykorzystując
funkcje: int binarySearch2(int* S, int n, int x) i 
int interpolationSearch2(int* S, int n, int x) proszę wykonać eksperyment porównujący
wyszukiwanie binarne i interpolacyjne pod względem liczy wykonywanych kroków.
W ramach eksperymentu porównanie należy powtórzyć dla różnych wartości x i różnych wartości n.
Szablon rozwiązania:

//Zadanie 6

int interpolationSearch2(int* S, int n, int x) { //wersja iteracyjna
}

//Zadanie 6 - test
    {
    int n;
    int *S;
    int x;
    //dla n = ....
    cout<<endl<<"n = ..."<<endl;
    //....
    initSorted(S,n);
    print(S,n);
    //wczytanie x
    cout<<binarySearch2(S,n,x)<<" ";<<endl;
    cout<<interpolationSearch2(S,n,x)<<endl;
    // …
}
*******************************************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void print(int* S, int n){
    cout << "[ ";
    int limit = (n > 20) ? 20 : n;
    for (int i=0; i<limit; i++) {
        cout << S[i] << " ";
    }
    if (n > 20) cout << "... ";
    cout << "]" << endl;
}

int linearSearch1(int* S, int n, int x) {
    for(int i=0; i<n; i++) {
        if(S[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch1(int* S, int n, int x){
    int lewy = 0;
    int prawy = n-1;
    
    while (lewy <= prawy) {
        int srodek = (lewy + prawy) / 2;
        
        if (S[srodek] == x) {
            return srodek;
        } 
        else if (S[srodek] < x) {
            lewy = srodek + 1;
        } 
        else {
            prawy = srodek - 1;
        }
    }
    return -1;
}

int linearSearch2(int* S, int n, int x) {
    int licznik = 0;
    for(int i=0; i<n; i++) {
        licznik ++;
        if(S[i] == x) {
            return licznik;
        }
    }
    return licznik;
}

int binarySearch2(int* S, int n, int x) {
    int lewy = 0;
    int prawy = n-1;
    int licznik = 0;
    
    while (lewy <= prawy) {
        licznik++;
        int srodek = (lewy + prawy) / 2;
        
        if (S[srodek] == x) {
            return licznik;
        } 
        else if (S[srodek] < x) {
            lewy = srodek + 1;
        } 
        else {
            prawy = srodek - 1;
        }
    }
    return licznik;
}

void initSorted(int* S, int n) {
    S[0] = rand() % 10;
    for (int i = 1; i < n; i++)
        S[i] = S[i - 1] + rand() % 10;
}


void runExperiment() {
    int sizes[] = { 10, 100, 1000, 10000, 50000, 100000 };
    int numSizes = 6;
    int trials = 100;

    cout << "=== ZADANIE 4 - EKSPERYMENT ===" << endl;
    cout << "Porownanie sredniej liczby krokow (prob: " << trials << ")" << endl;
    cout << "N (rozmiar)\tLiniowe (srednia)\tBinarne (srednia)" << endl;
    cout << "---------------------------------------------------------" << endl;

    for (int k = 0; k < numSizes; k++) {
        int n = sizes[k];
        
        // 1. Alokacja pamięci
        int* S = new int[n];
        
        // 2. Generowanie posortowanych danych
        initSorted(S, n);

        long long sumLinear = 0;
        long long sumBinary = 0;

        // 3. Wielokrotne powtarzanie próby
        for (int t = 0; t < trials; t++) {
            int randomIndex = rand() % n;
            int x = S[randomIndex];

            sumLinear += linearSearch2(S, n, x);
            sumBinary += binarySearch2(S, n, x);
        }

        // 4. Wyliczenie średniej
        double avgLinear = (double)sumLinear / trials;
        double avgBinary = (double)sumBinary / trials;

        // 5. Wyświetlenie wyników
        cout << n << "\t\t" << avgLinear << "\t\t\t" << avgBinary << endl;

        // Sprzątanie pamięci
        delete[] S;
    }
}

int interpolationSearch1(int* S, int n, int x) {
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi && x >= S[lo] && x <= S[hi]) {
        
        if (lo == hi) {
            if (S[lo] == x) return lo;
            return -1;
        }

        int pos = lo + (((double)(hi - lo) / (S[hi] - S[lo])) * (x - S[lo]));

        if (S[pos] == x) return pos;
        if (S[pos] < x) lo = pos + 1;
        else hi = pos - 1;
    }
    return -1;
}


int interpolationSearch2(int* S, int n, int x) {
    int lo = 0;
    int hi = n - 1;
    int kroki = 0;

    while (lo <= hi && x >= S[lo] && x <= S[hi]) {
        kroki++;
        
        if (lo == hi) {
            return kroki;
        }

        if (S[hi] == S[lo]) return kroki;

        int pos = lo + (((double)(hi - lo) / (S[hi] - S[lo])) * (x - S[lo]));

        if (S[pos] == x) return kroki;
        if (S[pos] < x) lo = pos + 1;
        else hi = pos - 1;
    }
    return kroki;
}


int main() {
    
    srand(time(NULL));
    
    // --- TEST ZADANIE 1 ---
    cout << "=== ZADANIE 1 - TEST (Liniowe - indeks) ===" << endl;
    {
        int n = 5;
        int* S = new int[n];
        S[0] = 50; S[1] = 10; S[2] = 40; S[3] = 20; S[4] = 30;
        cout << "Szukam 20. Indeks: " << linearSearch1(S, n, 20) << endl;
        delete[] S;
    }

    // --- TEST ZADANIE 2 ---
    cout << endl << "=== ZADANIE 2 - TEST (Binarne - indeks) ===" << endl;
    {
        int n = 5;
        int* S = new int[n]; // 10, 20, 30, 40, 50
        for(int i=0; i<n; i++) S[i] = (i+1)*10;
        cout << "Szukam 30. Indeks: " << binarySearch1(S, n, 30) << endl;
        delete[] S;
    }

    // --- TEST ZADANIE 3 ---
    cout << endl << "=== ZADANIE 3 - TEST (Zliczanie operacji) ===" << endl;
    
    // PRZYGOTOWANIE DANYCH
    int n = 15; 
    int* S = new int[n];
    for(int i=0; i<n; i++) S[i] = i;

    cout << "Tablica (rozmiar " << n << "): ";
    print(S, n);
    cout << endl;

    int x;

    // PRZYPADEK 1: Element na początku
    x = 0;
    cout << "Szukam: " << x << " (Poczatek)" << endl;
    cout << "  Liniowe kroki: " << linearSearch2(S, n, x) << endl;
    cout << "  Binarne kroki: " << binarySearch2(S, n, x) << endl;
    
    // PRZYPADEK 2: Element w środku
    x = 7;
    cout << "Szukam: " << x << " (Srodek)" << endl;
    cout << "  Liniowe kroki: " << linearSearch2(S, n, x) << endl;
    cout << "  Binarne kroki: " << binarySearch2(S, n, x) << endl;

    // PRZYPADEK 3: Element na końcu
    x = 14;
    cout << "Szukam: " << x << " (Koniec)" << endl;
    cout << "  Liniowe kroki: " << linearSearch2(S, n, x) << endl;
    cout << "  Binarne kroki: " << binarySearch2(S, n, x) << endl;

    delete[] S;
    
    // Zadanie 4
    runExperiment();
    
    // --- TEST ZADANIE 5 ---
    cout << endl << "=== ZADANIE 5 - TEST (Interpolacyjne - indeks) ===" << endl;
    {
        int n = 15;
        int* S = new int[n];
        
        for(int i=0; i<n; i++) {
            S[i] = i * 10; 
        }
        
        cout << "Tablica: ";
        print(S, n);

        int x = 70;
        cout << "Szukam " << x << ". Wynik: " << interpolationSearch1(S, n, x) << " (oczekiwany: 7)" << endl;

        delete[] S;
    }

    // --- ZADANIE 6 - TEST ---
    cout << endl << "=== ZADANIE 6 - EKSPERYMENT (Binary vs Interpolation) ===" << endl;
    {
        // Tablica rozmiarów do testów
        int testSizes[] = { 100, 5000, 30000 };
        
        for(int k=0; k < 3; k++) {
            int n = testSizes[k];
            int *S = new int[n];
            initSorted(S, n);
            
            cout << endl << "n = " << n << endl;
            cout << "Dane (poczatek): "; print(S, n);
            cout << "Szukana (x)\tBinary(kroki)\tInterp(kroki)" << endl;
            cout << "---------------------------------------------" << endl;
            
            // 1. Szukanie wartości z początku zakresu
            int x1 = S[rand() % (n/10)]; 
            cout << x1 << "\t\t" << binarySearch2(S, n, x1) << "\t\t" << interpolationSearch2(S, n, x1) << endl;
            
            // 2. Szukanie wartości ze środka zakresu
            int x2 = S[n/2]; 
            cout << x2 << "\t\t" << binarySearch2(S, n, x2) << "\t\t" << interpolationSearch2(S, n, x2) << endl;
            
            // 3. Szukanie wartości z końca zakresu
            int x3 = S[n - 1 - (rand() % 5)]; 
            cout << x3 << "\t\t" << binarySearch2(S, n, x3) << "\t\t" << interpolationSearch2(S, n, x3) << endl;
            
            // 4. Szukanie wartości, której nie ma (spoza zakresu wartości, ale w zakresie liczb)
            // Bierzemy wartość o 1 większą od środkowej (zakładając, że initSorted robi luki)
            int x4 = S[n/2] + 1;
            // Jeśli pechowo trafiliśmy w istniejącą, zwiększamy
            if (x4 == S[n/2+1]) x4++; 
            
            cout << x4 << " (brak)\t" << binarySearch2(S, n, x4) << "\t\t" << interpolationSearch2(S, n, x4) << endl;

            delete[] S;
        }
    }

    return 0;
}