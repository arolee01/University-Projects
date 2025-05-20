#ifndef LIBFILES_H
#define LIBFILES_H

#include <vector>
#include <string>

/*
 * Odczytuje dane wejœciowe z pliku
 * @param filename Nazwa pliku do odczytu
 * @return Wektor wektorów liczb ca³kowitych reprezentuj¹cych zestawy danych
 * @throw runtime_error jeœli nie mo¿na otworzyæ pliku
 */
std::vector<std::vector<int>> readInputData(const std::string& filename);

/*
 * Zapisuje wyniki do pliku
 * @param filename Nazwa pliku do zapisu
 * @param results Wektor wyników w postaci stringów
 * @throw runtime_error jeœli nie mo¿na otworzyæ pliku do zapisu
 */
void writeOutputData(const std::string& filename, const std::vector<std::string>& results);

#endif