#ifndef LIBARRAY_H
#define LIBARRAY_H

#include <iostream>
#include <climits>

/*
* Funkcja odpowiadajπca za tworzenie tablicy dwuwymiarowej
* @param n - liczba wierszy
* @param m - liczba kolumn
* @return Adres utworzonej tablicy
*/
int** f_createArray(int n, int m);

/*
* Funkcja odpowiadajπca za usuwanie tablicy dwuwymiarowej
* @param array - wskaünik do tablicy dwuwymiarowej
* @param n - liczba wierszy
*/
void f_deleteArray(int** array, int n);

/*
* Funkcja odpowiadajπca za wype≥nianie tablicy dwuwymiarowej danymi
* @param array - wskaünik do tablicy dwuwymiarowej
* @param n - liczba wierszy
* @param m - liczba kolumn
* @return true, jeúli dane sπ poprawne; false, jeúli dane wykraczajπ poza zakres
*/
bool f_fillArray(int** array, int n, int m);

#endif 