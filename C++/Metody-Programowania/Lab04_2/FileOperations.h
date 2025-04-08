#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <string>
#include <vector>

/**
 * @brief Klasa do operacji na plikach
 * @details Umo¿liwia odczyt i zapis danych zwi¹zanych z konwersj¹ wyra¿eñ
 */
class FileOperations {
public:
    /**
     * @brief Odczytuje linie z pliku wejœciowego
     * @param filename Nazwa pliku do odczytu
     * @return Wektor stringów zawieraj¹cy linie z pliku
     */
    static std::vector<std::string> readLines(const std::string& filename);

    /**
     * @brief Zapisuje wyniki konwersji do pliku wyjœciowego
     * @param filename Nazwa pliku do zapisu
     * @param results Wektor par (wejœcie, wynik) do zapisu
     * @return true jeœli zapis siê powiód³, false w przeciwnym przypadku
     */
    static bool saveResults(const std::string& filename, const std::vector<std::pair<std::string, std::string>>& results);
};

#endif 