#include "LibMSE.h"
#include "LibFiles.h"
#include "LibTables.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <fstream>

using namespace std;

double f_calculateMSE(double** grid1, double** grid2, int cols) {
    double sumY = 0.0;
    double sumX = 0.0;
    int dataPoints = 0;

    // Obliczamy sumê kwadratów ró¿nic dla wspó³rzêdnych Y i X
    // Zaczynamy od indeksu 6, aby pomin¹æ parametry modelu
    for (int j = 6; j < cols; j++) {
        sumY += pow(grid1[0][j] - grid2[0][j], 2);
        sumX += pow(grid1[1][j] - grid2[1][j], 2);
        dataPoints++;
    }

    // Obliczamy pierwiastek z sumy kwadratów ró¿nic podzielonej przez liczbê punktów danych
    return sqrt((sumY + sumX) / dataPoints);
}

void f_processMotorModel(const string gridFilename, const string nmFilename, const string resultFilename, const string motorType) {
    int gridRows, gridCols;
    int nmRows, nmCols;

    double** gridData = f_readDataFromFile(gridFilename, gridRows, gridCols);
    double** nmData = f_readDataFromFile(nmFilename, nmRows, nmCols);

    if (gridData == nullptr || nmData == nullptr) {
        cerr << "B³¹d podczas wczytywania danych!" << endl;
        if (gridData != nullptr) f_freeMemory(gridData, gridRows);
        if (nmData != nullptr) f_freeMemory(nmData, nmCols);
        return;
    }

    int gridCount = gridRows / 2;

    double* mseValues = new double[gridCount];

    int minMseIndex = 0;
    double minMse = numeric_limits<double>::max();

    for (int i = 0; i < gridCount; i++) {
        double** currentGrid = f_extractGrid(gridData, i, 2, gridCols);

        mseValues[i] = f_calculateMSE(currentGrid, nmData, gridCols);

        if (mseValues[i] < minMse) {
            minMse = mseValues[i];
            minMseIndex = i;
        }

        f_freeMemory(currentGrid, 2);
    }

    double** bestGrid = f_extractGrid(gridData, minMseIndex, 2, gridCols);

    f_saveResultsToFile(resultFilename, mseValues, gridCount, minMseIndex, bestGrid, gridCols);

    f_freeMemory(gridData, gridRows);
    f_freeMemory(nmData, nmRows);
    f_freeMemory(bestGrid, 2);
    delete[] mseValues;
}