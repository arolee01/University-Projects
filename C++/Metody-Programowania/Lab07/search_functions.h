#ifndef SEARCH_FUNCTIONS_H
#define SEARCH_FUNCTIONS_H

struct Position {
    int row;
    int col;
};

/*
 * Wyszukuje pierwsze wyst¹pienie elementu w posortowanej tablicy 2D (rekurencyjnie)
 * @param matrix Dwuwymiarowa tablica posortowana niemalej¹co
 * @param rows Liczba wierszy tablicy
 * @param cols Liczba kolumn tablicy
 * @param target Wartoœæ do znalezienia
 * @param r Aktualny wiersz (parametr domyœlny: 0)
 * @param c Aktualna kolumna (parametr domyœlny: 0)
 * @return Pozycja pierwszego wyst¹pienia lub (-1,-1) jeœli nie znaleziono
 */
Position findFirstRecursive(int** matrix, int rows, int cols, int target, int r = 0, int c = 0);

/*
 * Wyszukuje ostatnie wyst¹pienie elementu w posortowanej tablicy 2D (rekurencyjnie)
 * @param matrix Dwuwymiarowa tablica posortowana niemalej¹co
 * @param rows Liczba wierszy tablicy
 * @param cols Liczba kolumn tablicy
 * @param target Wartoœæ do znalezienia
 * @param r Aktualny wiersz (parametr domyœlny: -1)
 * @param c Aktualna kolumna (parametr domyœlny: -1)
 * @return Pozycja ostatniego wyst¹pienia lub (-1,-1) jeœli nie znaleziono
 */
Position findLastRecursive(int** matrix, int rows, int cols, int target, int r = -1, int c = -1);

/*
 * Wyszukuje pierwsze wyst¹pienie elementu w posortowanej tablicy 2D (iteracyjnie)
 * Wykorzystuje algorytm schodkowy rozpoczynaj¹cy od prawego górnego rogu
 * @param matrix Dwuwymiarowa tablica posortowana niemalej¹co
 * @param rows Liczba wierszy tablicy
 * @param cols Liczba kolumn tablicy
 * @param target Wartoœæ do znalezienia
 * @return Pozycja pierwszego wyst¹pienia lub (-1,-1) jeœli nie znaleziono
 */
Position findFirstIterative(int** matrix, int rows, int cols, int target);

/*
 * Wyszukuje ostatnie wyst¹pienie elementu w posortowanej tablicy 2D (iteracyjnie)
 * Wykorzystuje algorytm schodkowy rozpoczynaj¹cy od lewego dolnego rogu
 * @param matrix Dwuwymiarowa tablica posortowana niemalej¹co
 * @param rows Liczba wierszy tablicy
 * @param cols Liczba kolumn tablicy
 * @param target Wartoœæ do znalezienia
 * @return Pozycja ostatniego wyst¹pienia lub (-1,-1) jeœli nie znaleziono
 */
Position findLastIterative(int** matrix, int rows, int cols, int target);

/*
 * Wyœwietla wynik wyszukiwania w okreœlonym formacie
 * @param prefix Prefiks opisuj¹cy typ wyszukiwania 
 * @param target Wartoœæ wyszukiwana
 * @param pos Znaleziona pozycja lub (-1,-1) jeœli nie znaleziono
 */
void printResult(const char* prefix, int target, Position pos);

#endif