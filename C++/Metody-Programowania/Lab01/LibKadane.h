#ifndef LIBKADANE_H
#define LIBKADANE_H

#include <iostream>

/*
* Funkcja odpowiadaj¹ca za znajdowanie maksymalnej sumy podtablicy jednowymiarowej
* @param array - wskaŸnik do tablicy jednowymiarowej
* @param n - rozmiar tablicy
* @param startIndex - indeks pocz¹tkowy podtablicy
* @param endIndex - indeks koñcowy podtablicy
* @return Maksymaln¹ sume tablicy
*/
int f_kadane(int* array, int n, int startIndex, int endIndex);

/*
* Funkcja odpowiadaj¹ca za znajdowanie maksymalnej sumy podtablicy dwuwymiarowej
* @param array - wskaŸnik do tablicy dwuwymiarowej
* @param n - liczba wieszy
* @param m - liczba kolumn
* @return Maksymaln¹ sumê podtablicy
*/
int f_maxSubarraySum(int** array, int n, int m);

/*
* Funkcja odpowiadaj¹ca za wypisywanie wyniku
* @param result - wynik do wypisania
*/
void f_showResult(int result);

#endif