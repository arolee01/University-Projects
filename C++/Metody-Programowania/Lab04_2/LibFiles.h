#ifndef LIBFILES_H
#define LIBFILES_H

#include <fstream>
#include <string>

using namespace std;

/*
 * Struktura przechowuj¹ca pojedynczy zestaw danych
 * @param dataSize Liczba elementów w tablicy danych
 * @param data Tablica zawieraj¹ca dane wejœciowe
 * @param numbersAmount Liczba zapytañ dla zestawu
 * @param searchedNumbers Tablica zawieraj¹ca wartoœci do wyszukania
 */
struct DataSet {
    int dataSize;
    int* data;
    int numbersAmount;
    int* searchedNumbers;
};

/*
 * Odczytuje dane z pliku wejœciowego
 * @param filename Nazwa pliku wejœciowego do odczytu
 * @param numOfSets Liczba wczytanych zestawów danych
 * @param dataSets WskaŸnik do tablicy struktur DataSet
 * @return true jeœli odczyt siê powiód³, false jeœli nie
 */
bool f_readData(const string& filename, int& numOfSets, DataSet*& dataSets);

/*
 * Przetwarza dane i zapisuje wyniki do pliku wyjœciowego
 * @param filename Nazwa pliku wyjœciowego do zapisu
 * @param numOfSets Liczba zestawów danych do przetworzenia
 * @param dataSets Tablica struktur DataSet zawieraj¹ca dane
 * @return true jeœli zapis siê powiód³, false w przypadku b³êdu
 */
bool f_processAndSaveData(const string& filename, int numOfSets, DataSet* dataSets);

/*
 * Zwalnia pamiêæ
 * @param numOfSets Liczba zestawów danych do zwolnienia
 * @param dataSets Tablica struktur DataSet do zwolnienia
 */
void f_freeMemory(int numOfSets, DataSet* dataSets);

#endif