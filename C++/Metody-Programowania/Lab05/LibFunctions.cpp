#include "LibFunctions.h"

/**
 * x^n = x * x^(n-1), gdzie x^0 = 1
 */
int power(int x, int n) {
    // Warunek zatrzymania: x^0 = 1
    return n == 0 ? 1 : x * power(x, n - 1); 
}

/*
 * Oblicza wartoœæ wielomianu a[0] + a[1]*x + ... + a[N]*x^N
 * Dzia³a rekurencyjnie sumuj¹c sk³adniki od koñca:
 * a[N]*x^N + a[N-1]*x^(N-1) + ... + a[0]
 */
int f_wielomian(int N, const int* a, int x) {
    return N < 0 ? 0 : a[N] * power(x, N) + f_wielomian(N - 1, a, x);
}

/*
 * Znajduje najwiêkszy element w tablicy t o rozmiarze N.
 * Algorytm rekurencyjnie porównuje bie¿¹cy element z maksimum z reszty tablicy.
 */
const int* f_maximum(int N, const int* t) {
    // Kiedy dane s¹ b³êdne 
    if (N <= 0 || !t) return nullptr; 
    // Warunek zatrzymania: tablica 1-elementowa
    if (N == 1) return t; 

    // Rekurencja dla reszty tablicy
    const int* max_rest = f_maximum(N - 1, t + 1); 
    // Porównanie bie¿¹cego elementu z maksimum reszty
    return *t >= *max_rest ? t : max_rest; 
}

/*
 * Oblicza symbol Newtona "N po K" rekurencyjnie ze wzoru:
 * (N K) = (N-1 K-1) + (N-1 K) dla 0 < K < N
 * Z dodatkowymi warunkami brzegowymi
 */
int f_newton(int N, int K) {
    if (N > 33 || K > 33) return -1;
    // Dla K > N wynik to 0
    if (K > N) return 0; 
    // Warunki brzegowe
    if (K == 0 || K == N) return 1; 

    return f_newton(N - 1, K - 1) + f_newton(N - 1, K); 
}

/*
 * Przechodzi rekurencyjnie przez tablicê, zliczaj¹c i sumuj¹c elementy spe³niaj¹ce warunek f.
 */
unsigned int f_sredniaWarunkowa_pomocnicza(const int* b, const int* e, bool (*f)(int), double& sum, unsigned int count) {
    // Warunek zatrzymania: koniec zakresu
    if (b == e) return count; 

    // Jeœli element spe³nia warunek
    if (f(*b)) { 
        // Dodaje do sumy
        sum += *b; 
        // Zwiêksaz licznik
        return f_sredniaWarunkowa_pomocnicza(b + 1, e, f, sum, count + 1); 
    }
    return f_sredniaWarunkowa_pomocnicza(b + 1, e, f, sum, count); // Pomija element
}

/*
 * Oblicza œredni¹ arytmetyczn¹ elementów spe³niaj¹cych warunek f w zakresie [b,e).
 * Jeœli ¿aden element nie spe³nia warunku, s pozostaje niezmienione.
 */
unsigned int f_sredniaWarunkowa(double& s, bool (*f)(int), const int* b, const int* e) {
    // Sprawdzenie poprawnoœci danych
    if (!f || !b || !e || b >= e) return 0; 

    double sum = 0;
    unsigned int count = f_sredniaWarunkowa_pomocnicza(b, e, f, sum, 0);

    // Oblicza œredni¹ jeœli s¹ elementy
    if (count > 0) s = sum / count; 
    // Zwraca liczbê elementów spe³niaj¹cych warunek
    return count; 
}

/*
 * Sprawdza warunki i oblicza sumy poœrednie rekurencyjnie.
 */
bool f_sumaWazona_pomocnicza(const double* b, const double* e, const double* a, double& sum, double& weights_sum) {
    // Warunek zatrzymania + sprawdzenie sumy wag
    if (b == e) return weights_sum <= 1.0 && weights_sum >= 0.0;

    if (*b < 0) return false; // Jeœli mniejsza od 0 - b³¹d

    // Oblicza bie¿¹ce sumy i kontynuuje rekurencjê
    sum += (*b) * (*a);
    weights_sum += *b;
    return f_sumaWazona_pomocnicza(b + 1, e, a + 1, sum, weights_sum);
}

/*
 * Sumuje wa¿one elementy i dodaje sk³adnik koryguj¹cy.
 */
bool f_sumaWazona(double& s, const double* b, const double* e, const double* a) {
    double sum = 0;
    double weights_sum = 0;

    // Wywo³anie funkcji pomocniczej
    bool valid = f_sumaWazona_pomocnicza(b, e, a, sum, weights_sum);

    if (valid) 
        s = sum + a[e - b] * (1.0 - weights_sum); 

    return valid;
}