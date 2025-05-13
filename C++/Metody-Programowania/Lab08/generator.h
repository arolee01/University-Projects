#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>
#include <string>

 /*
  * Generuje liczby pseudolosowe za pomoc¹ Liniowej Metody Kongruencyjnej
  * @param a Mno¿nik generatora
  * @param c Przyrost generatora
  * @param m Modu³ generatora
  * @param seed Ziarno generatora
  * @param n Liczba liczb do wygenerowania
  * @return Wektor wygenerowanych liczb pseudolosowych
  */
std::vector<int> generateLCG(int a, int c, int m, int seed, int n);

/*
 * Generuje liczby pseudolosowe za pomoc¹ Addytywnej Metody Kongruencyjnej
 * z automatycznie ustawionymi parametrami (n=6, j=2, k=5)
 * @param m Modu³ generatora
 * @param n Liczba liczb do wygenerowania
 * @return Wektor wygenerowanych liczb pseudolosowych
 */
std::vector<int> generateAdditive(int m, int n);

/*
 * Zapisuje wektor liczb do pliku tekstowego
 * @param numbers Wektor liczb do zapisania
 * @param filename Nazwa pliku wyjœciowego
 */
void saveToFile(const std::vector<int>& numbers, const std::string& filename);

#endif // GENERATOR_H