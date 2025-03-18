#ifndef LIBFILES_H
#define LIBFILES_H

#include <string>
#include <fstream>

using namespace std;

/**
 * Wczytuje dane z pliku tekstowego do tablicy dwuwymiarowej
 * @param filename Nazwa pliku
 * @param rows Liczba wierszy w pliku
 * @param cols Liczba kolumn w pliku
 * @return Tablica dwuwymiarowa zawieraj¹ca dane z pliku
 */
double** f_readDataFromFile(const string filename, int rows, int cols);

/**
 * Zapisuje wyniki do pliku tekstowego
 * @param filename Nazwa pliku 
 * @param mseValues Tablica z wartoœciami MSE dla wszystkich siatek
 * @param gridCount Liczba siatek
 * @param minMseIndex Indeks najlepszego dopasowania
 * @param bestGrid Tablica z danymi najlepszego dopasowania
 * @param cols Liczba kolumn w danych
 */
void f_saveResultsToFile(const string filename, double* mseValues, int gridCount, int minMseIndex, double** bestGrid, int cols);

#endif // LIBFILES_H
