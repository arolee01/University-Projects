#ifndef CTABLICA_H
#define CTABLICA_H

#include <vector>
#include <utility>

class cTablica {
private:
    std::vector<int> data;
    
    // Metody pomocnicze dla quicksort
    int partitionLomuto(std::vector<int>& arr, int low, int high, 
                       long long& comparisons, long long& swaps);
    int partitionHoare(std::vector<int>& arr, int low, int high, 
                      long long& comparisons, long long& swaps);
    void quickSortLomuto(std::vector<int>& arr, int low, int high, 
                        long long& comparisons, long long& swaps);
    void quickSortHoare(std::vector<int>& arr, int low, int high, 
                       long long& comparisons, long long& swaps);
    
    // Metody pomocnicze dla heap sort
    void heapify(std::vector<int>& arr, int n, int i, 
                long long& comparisons, long long& swaps);
    void buildMaxHeap(std::vector<int>& arr, int n, 
                     long long& comparisons, long long& swaps);

public:
    cTablica();
    
    cTablica(const std::vector<int>& inputData);
    
    /**
     * Ustawia dane do sortowania
     * @param inputData wektor danych
     */
    void setData(const std::vector<int>& inputData);
    
    /**
     * Zwraca aktualne dane
     * @return wektor danych
     */
    std::vector<int> getData() const;
    
    /**
     * Sortowanie bąbelkowe wahadłowe (shaker sort)
     * @return para (liczba porównań, liczba przestawień)
     */
    std::pair<long long, long long> shakerSort();
    
    /**
     * Sortowanie szybkie z podziałem Lomuto
     * @return para (liczba porównań, liczba przestawień)
     */
    std::pair<long long, long long> quickSortLomuto();
    
    /**
     * Sortowanie szybkie z podziałem Hoare'a
     * @return para (liczba porównań, liczba przestawień)
     */
    std::pair<long long, long long> quickSortHoare();
    
    /**
     * Sortowanie przez kopcowanie (heap sort)
     * @return para (liczba porównań, liczba przestawień)
     */
    std::pair<long long, long long> heapSort();
    
    /**
     * Sprawdza czy tablica jest posortowana
     * @return true jeśli posortowana, false w przeciwnym wypadku
     */
    bool isSorted() const;
};

#endif // CTABLICA_H