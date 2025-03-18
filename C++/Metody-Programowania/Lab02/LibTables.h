#ifndef LIBTABLES_H
#define LIBTABLES_H

using namespace std;

/**
 * Zwalnia pamiêæ zajmowan¹ przez tablicê dwuwymiarow¹
 * @param data Tablica do zwolnienia
 * @param rows Liczba wierszy w tablicy
 */
void f_freeMemory(double** data, int rows);

/**
 * Kopiuje zawartoœæ jednej tablicy do drugiej
 * @param source Tablica Ÿród³owa
 * @param destination Tablica docelowa
 * @param rows Liczba wierszy
 * @param cols Liczba kolumn
 */
void f_copyTable(double** source, double** destination, int rows, int cols);

/**
 * Wydziela pojedyncz¹ siatkê z pliku zawieraj¹cego wiele siatek
 * @param data Dane z pliku wejœciowego
 * @param gridIndex Indeks siatki do wyodrêbnienia
 * @param rows Liczba wierszy jednej siatki (zwykle 2)
 * @param cols Liczba kolumn
 * @return Wyodrêbniona siatka jako tablica dwuwymiarowa
 */
double** f_extractGrid(double** data, int gridIndex, int rows, int cols);

#endif 