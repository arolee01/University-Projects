#ifndef CSORT_TABLICY_H
#define CSORT_TABLICY_H

#include "cTablica.h"
#include <vector>
#include <string>

enum class DataType {
    RANDOM,
    SORTED_ASC,
    SORTED_DESC,
    PARTIALLY_SORTED
};

enum class SortMethod {
    SHAKER_SORT,
    QUICK_SORT_LOMUTO,
    QUICK_SORT_HOARE,
    HEAP_SORT
};

struct SortResult {
    SortMethod method;
    DataType dataType;
    int arraySize;
    long long comparisons;
    long long swaps;
    double timeMs;
    
    SortResult(SortMethod m, DataType dt, int size, long long comp, long long sw, double time)
        : method(m), dataType(dt), arraySize(size), comparisons(comp), swaps(sw), timeMs(time) {}
};

class cSortTablicy {
private:
    std::vector<SortResult> results;
    
    /**
     * Generuje dane losowe
     * @param size rozmiar tablicy
     * @return wektor z danymi losowymi
     */
    std::vector<int> generateRandomData(int size);
    
    /**
     * Generuje dane posortowane rosnąco
     * @param size rozmiar tablicy
     * @return wektor z danymi posortowanymi rosnąco
     */
    std::vector<int> generateSortedAscData(int size);
    
    /**
     * Generuje dane posortowane malejąco
     * @param size rozmiar tablicy
     * @return wektor z danymi posortowanymi malejąco
     */
    std::vector<int> generateSortedDescData(int size);
    
    /**
     * Generuje dane częściowo posortowane (10% na złych pozycjach)
     * @param size rozmiar tablicy
     * @return wektor z danymi częściowo posortowanymi
     */
    std::vector<int> generatePartiallySortedData(int size);
    
    /**
     * Konwertuje enum DataType na string
     * @param type typ danych
     * @return nazwa typu jako string
     */
    std::string dataTypeToString(DataType type);
    
    /**
     * Konwertuje enum SortMethod na string
     * @param method metoda sortowania
     * @return nazwa metody jako string
     */
    std::string sortMethodToString(SortMethod method);
    
    /**
     * Wykonuje test sortowania dla danej metody i typu danych
     * @param method metoda sortowania
     * @param dataType typ danych
     * @param size rozmiar tablicy
     */
    void runSortTest(SortMethod method, DataType dataType, int size);

public:
    cSortTablicy();
    
    /**
     * Wprowadza elementy z klawiatury
     * @param count liczba elementów do wprowadzenia
     * @return wektor wprowadzonych elementów
     */
    std::vector<int> inputFromKeyboard(int count);
    
    /**
     * Generuje losowe elementy
     * @param count liczba elementów do wygenerowania
     * @return wektor losowych elementów
     */
    std::vector<int> generateRandomElements(int count);
    
    /**
     * Uruchamia wszystkie testy dla wszystkich kombinacji
     * @param sizes wektor rozmiarów tablic do testowania
     */
    void runAllTests(const std::vector<int>& sizes);
    
    /**
     * Testuje wszystkie algorytmy dla różnych przypadków danych dla danego rozmiaru
     * @param rozmiar rozmiar tablicy do testowania
     */
    void testujDlaRoznychPrzypadkow(int rozmiar);

    /**
     * Zapisuje wyniki do pliku tekstowego w formie tabeli
     * @param filename nazwa pliku
     * @return true jeśli zapis się powiódł, false w przeciwnym wypadku
     */
    bool saveResultsToFile(const std::string& filename);
    
    /**
     * Wyświetla wyniki na konsoli
     */
    void displayResults();
    
    /**
     * Czyści zapisane wyniki
     */
    void clearResults();
    
    /**
     * Testuje konkretną metodę sortowania na danych
     * @param data dane do posortowania
     * @param method metoda sortowania
     * @return wyniki sortowania (porównania, przestawienia, czas)
     */
    SortResult testSortMethod(const std::vector<int>& data, SortMethod method);
};

#endif // CSORT_TABLICY_H