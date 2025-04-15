#ifndef LIBFUNCTIONS_H
#define LIBFUNCTIONS_H

/**
 * @brief Oblicza wartość wielomianu o podanych współczynnikach
 * @param N Stopień wielomianu
 * @param a Tablica współczynników wielomianu (długość N+1)
 * @param x Punkt w którym obliczamy wartość wielomianu
 * @return Wartość wielomianu w punkcie x
 */
int f_wielomian(int N, const int* a, int x);

/**
 * @brief Znajduje największy element w tablicy
 * @param N Liczba elementów w tablicy
 * @param t Tablica wejściowa
 * @return Wskaźnik do największego elementu lub nullptr dla błędnych danych
 */
const int* f_maximum(int N, const int* t);

/**
 * @brief Oblicza wartość symbolu Newtona (N po K)
 * @param N Górny parametr symbolu Newtona
 * @param K Dolny parametr symbolu Newtona
 * @return Wartość symbolu Newtona lub:
 * 0 jeśli K > N
 * -1 jeśli N lub K > 33
 */
int f_newton(int N, int K);

/**
 * @brief Oblicza średnią arytmetyczną elementów spełniających warunek
 * @param s Referencja do zmiennej przechowującej wynik
 * @param f Wskaźnik do funkcji warunkowej
 * @param b Początek zakresu danych
 * @param e Koniec zakresu danych (za ostatnim elementem)
 * @return Liczba elementów spełniających warunek
 */
unsigned int f_sredniaWarunkowa(double& s, bool (*f)(int), const int* b, const int* e);

/**
 * @brief Oblicza sumę ważoną zgodnie ze specyfikacją zadania
 * @param s Referencja do zmiennej wynikowej
 * @param b Początek zakresu wag
 * @param e Koniec zakresu wag
 * @param a Tablica wartości
 * @return true jeśli warunki są spełnione, false w przeciwnym przypadku
 */
bool f_sumaWazona(double& s, const double* b, const double* e, const double* a);

#endif