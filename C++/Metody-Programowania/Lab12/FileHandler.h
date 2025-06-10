#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <vector>
#include <fstream>

class FileHandler {
public:
    /**
     * Zapisuje wektor liczb do pliku tekstowego w formie kolumny
     * @param filename Nazwa pliku do zapisu
     * @param numbers Wektor liczb do zapisu
     * @return true jesli zapis sie powiodl, false w przeciwnym wypadku
     */
    bool saveToFile(const std::string& filename, const std::vector<int>& numbers);
};

#endif // FILE_HANDLER_H