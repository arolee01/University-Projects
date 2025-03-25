#ifndef LIBTABLES_H
#define LIBTABLES_H

/*
 * Zlicza wyst¹pienia zadanej wartoœci w posortowanej tablicy
 * @param arr Tablica wejœciowa (musi byæ posortowana)
 * @param size Rozmiar tablicy wejœciowej
 * @param target Wartoœæ do zliczenia 
 * @return Liczba wyst¹pieñ wartoœci w tablicy (0 jeœli nie znaleziono)
 */
int f_countOccurrences(int* arr, int size, int target);

/*
 * Wyszukuje indeks wartoœci w posortowanej tablicy metod¹ interpolacyjn¹
 * @param arr Tablica wejœciowa (musi byæ posortowana)
 * @param size Rozmiar tablicy wejœciowej
 * @param target Wartoœæ do znalezienia
 * @return Indeks pierwszego wyst¹pienia wartoœci lub -1 jeœli nie znaleziono
 */
int f_interpolationSearch(int* arr, int size, int target);

/*
 * Usuwa duplikaty z posortowanej tablicy
 * @param arr Tablica wejœciowa (musi byæ posortowana)
 * @param size Rozmiar tablicy wejœciowej
 * @param newSize [out] Rozmiar wynikowej tablicy bez duplikatów
 * @return WskaŸnik do nowej tablicy bez duplikatów (nale¿y zwolniæ pamiêæ)
 */
int* f_removeDuplicates(int* arr, int size, int& newSize);

#endif