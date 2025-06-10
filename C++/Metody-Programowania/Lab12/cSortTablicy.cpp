#include "cSortTablicy.h"
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <stdexcept>

cSortTablicy::cSortTablicy() {}

std::vector<int> cSortTablicy::generateRandomData(int size) {
    std::vector<int> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, size * 10);
    
    for (int i = 0; i < size; i++) {
        data[i] = dis(gen);
    }
    
    return data;
}

std::vector<int> cSortTablicy::generateSortedAscData(int size) {
    std::vector<int> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = i + 1;
    }
    return data;
}

std::vector<int> cSortTablicy::generateSortedDescData(int size) {
    std::vector<int> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = size - i;
    }
    return data;
}

std::vector<int> cSortTablicy::generatePartiallySortedData(int size) {
    std::vector<int> data = generateSortedAscData(size);
    
    // Przestaw 10% elementów na losowe pozycje
    int swapCount = size / 10;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, size - 1);
    
    for (int i = 0; i < swapCount; i++) {
        int pos1 = dis(gen);
        int pos2 = dis(gen);
        std::swap(data[pos1], data[pos2]);
    }
    
    return data;
}

std::string cSortTablicy::dataTypeToString(DataType type) {
    switch (type) {
        case DataType::RANDOM:
            return "losowe";
        case DataType::SORTED_ASC:
            return "posortowane rosnąco";
        case DataType::SORTED_DESC:
            return "posortowane malejąco";
        case DataType::PARTIALLY_SORTED:
            return "częściowo uporządkowane";
        default:
            return "nieznane";
    }
}

std::string cSortTablicy::sortMethodToString(SortMethod method) {
    switch (method) {
        case SortMethod::SHAKER_SORT:
            return "Sortowanie wahadłowe";
        case SortMethod::QUICK_SORT_LOMUTO:
            return "Quick Sort (Lomuto)";
        case SortMethod::QUICK_SORT_HOARE:
            return "Quick Sort (Hoare)";
        case SortMethod::HEAP_SORT:
            return "Heap Sort";
        default:
            return "Nieznana metoda";
    }
}

std::vector<int> cSortTablicy::inputFromKeyboard(int count) {
    std::vector<int> data(count);
    std::cout << "Wprowadź " << count << " liczb całkowitych:\n";
    
    for (int i = 0; i < count; i++) {
        std::cout << "Element " << (i + 1) << ": ";
        while (!(std::cin >> data[i])) {
            std::cout << "Błędna wartość! Wprowadź liczbę całkowitą: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
    
    return data;
}

std::vector<int> cSortTablicy::generateRandomElements(int count) {
    return generateRandomData(count);
}

SortResult cSortTablicy::testSortMethod(const std::vector<int>& data, SortMethod method) {
    cTablica tablica(data);
    
    auto start = std::chrono::high_resolution_clock::now();
    std::pair<long long, long long> result;
    
    try {
        switch (method) {
            case SortMethod::SHAKER_SORT:
                result = tablica.shakerSort();
                break;
            case SortMethod::QUICK_SORT_LOMUTO:
                result = tablica.quickSortLomuto();
                break;
            case SortMethod::QUICK_SORT_HOARE:
                result = tablica.quickSortHoare();
                break;
            case SortMethod::HEAP_SORT:
                result = tablica.heapSort();
                break;
            default:
                throw std::invalid_argument("Nieznana metoda sortowania");
        }
    } catch (const std::exception& e) {
        std::cerr << "Błąd podczas sortowania: " << e.what() << std::endl;
        throw;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    double timeMs = duration.count() / 1000.0;
    
    // Sprawdź czy tablica jest posortowana
    if (!tablica.isSorted()) {
        throw std::runtime_error("Błąd sortowania - tablica nie jest posortowana!");
    }
    
    return SortResult(method, DataType::RANDOM, data.size(), result.first, result.second, timeMs);
}

void cSortTablicy::runSortTest(SortMethod method, DataType dataType, int size) {
    std::vector<int> data;
    
    switch (dataType) {
        case DataType::RANDOM:
            data = generateRandomData(size);
            break;
        case DataType::SORTED_ASC:
            data = generateSortedAscData(size);
            break;
        case DataType::SORTED_DESC:
            data = generateSortedDescData(size);
            break;
        case DataType::PARTIALLY_SORTED:
            data = generatePartiallySortedData(size);
            break;
    }
    
    try {
        SortResult result = testSortMethod(data, method);
        result.dataType = dataType;
        results.push_back(result);
        
        std::cout << "Test ukończony: " << sortMethodToString(method) 
                  << " na danych " << dataTypeToString(dataType) 
                  << " (rozmiar: " << size << ")\n";
    } catch (const std::exception& e) {
        std::cerr << "Błąd w teście: " << e.what() << std::endl;
    }
}

void cSortTablicy::runAllTests(const std::vector<int>& sizes) {
    clearResults();
    
    std::vector<SortMethod> methods = {
        SortMethod::SHAKER_SORT,
        SortMethod::QUICK_SORT_LOMUTO,
        SortMethod::QUICK_SORT_HOARE,
        SortMethod::HEAP_SORT
    };
    
    std::vector<DataType> dataTypes = {
        DataType::RANDOM,
        DataType::SORTED_ASC,
        DataType::SORTED_DESC,
        DataType::PARTIALLY_SORTED
    };
    
    std::cout << "Rozpoczynanie testów sortowania...\n";
    
    for (SortMethod method : methods) {
        for (DataType dataType : dataTypes) {
            for (int size : sizes) {
                std::cout << "Testowanie: " << sortMethodToString(method) 
                          << " - " << dataTypeToString(dataType) 
                          << " - rozmiar: " << size << std::endl;
                runSortTest(method, dataType, size);
            }
        }
    }
    
    std::cout << "Wszystkie testy zakończone!\n";
}

bool cSortTablicy::saveResultsToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    
    // Nagłówek tabeli
    file << std::left << std::setw(25) << "Nazwa metody sortowania"
         << std::setw(15) << "Długość tablicy"
         << std::setw(30) << "Rodzaj tablicy"
         << std::setw(20) << "Liczba porównań"
         << std::setw(20) << "Liczba przestawień"
         << std::setw(15) << "Czas [ms]" << std::endl;
    
    file << std::string(125, '-') << std::endl;
    
    // Dane
    for (const auto& result : results) {
        file << std::left << std::setw(25) << sortMethodToString(result.method)
             << std::setw(15) << result.arraySize
             << std::setw(30) << dataTypeToString(result.dataType)
             << std::setw(20) << result.comparisons
             << std::setw(20) << result.swaps
             << std::setw(15) << std::fixed << std::setprecision(3) << result.timeMs << std::endl;
    }
    
    file.close();
    return true;
}

void cSortTablicy::displayResults() {
    std::cout << std::left << std::setw(25) << "Nazwa metody sortowania"
              << std::setw(15) << "Długość tablicy"
              << std::setw(30) << "Rodzaj tablicy"
              << std::setw(20) << "Liczba porównań"
              << std::setw(20) << "Liczba przestawień"
              << std::setw(15) << "Czas [ms]" << std::endl;
    
    std::cout << std::string(125, '-') << std::endl;
    
    for (const auto& result : results) {
        std::cout << std::left << std::setw(25) << sortMethodToString(result.method)
                  << std::setw(15) << result.arraySize
                  << std::setw(30) << dataTypeToString(result.dataType)
                  << std::setw(20) << result.comparisons
                  << std::setw(20) << result.swaps
                  << std::setw(15) << std::fixed << std::setprecision(3) << result.timeMs << std::endl;
    }
}

void cSortTablicy::testujDlaRoznychPrzypadkow(int rozmiar) {
    clearResults();

    std::vector<SortMethod> methods = {
        SortMethod::SHAKER_SORT,
        SortMethod::QUICK_SORT_LOMUTO,
        SortMethod::QUICK_SORT_HOARE,
        SortMethod::HEAP_SORT
    };

    std::vector<DataType> dataTypes = {
        DataType::RANDOM,
        DataType::SORTED_ASC,
        DataType::SORTED_DESC,
        DataType::PARTIALLY_SORTED
    };

    std::cout << "Rozpoczynanie testów dla rozmiaru: " << rozmiar << std::endl;

    for (SortMethod method : methods) {
        for (DataType dataType : dataTypes) {
            std::cout << "Testowanie: " << sortMethodToString(method)
                      << " - " << dataTypeToString(dataType) << std::endl;
            runSortTest(method, dataType, rozmiar);
        }
    }

    // Zapisz wyniki do pliku
    std::string filename = "wyniki_sortowania_" + std::to_string(rozmiar) + ".txt";
    if (saveResultsToFile(filename)) {
        std::cout << "Wyniki zapisane do pliku: " << filename << std::endl;
    } else {
        std::cerr << "Błąd zapisu do pliku: " << filename << std::endl;
    }
}

void cSortTablicy::clearResults() {
    results.clear();
}