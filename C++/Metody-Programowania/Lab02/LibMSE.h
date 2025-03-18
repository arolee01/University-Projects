#ifndef LIBMSE_H
#define LIBMSE_H

#include <string>

using namespace std;

/**
 * Oblicza b³¹d œredniokwadratowy (MSE) miêdzy dwiema siatkami
 * @param grid1 Pierwsza siatka
 * @param grid2 Druga siatka
 * @param cols Liczba kolumn w siatkach
 * @return Wartoœæ b³êdu MSE
 */
double f_calculateMSE(double** grid1, double** grid2, int cols);

/**
 * Przetwarza model silnika - znajduje najlepsze dopasowanie i zapisuje wyniki
 * @param gridFilename Plik z siatkami identyfikacyjnymi
 * @param nmFilename Plik z nieznanym modelem
 * @param resultFilename Nazwa pliku, do którego bêd¹ zapisane dane
 * @param motorType Typ silnika (opis)
 */
void f_processMotorModel(const string gridFilename, const string nmFilename, const string resultFilename, const string motorType);

#endif 