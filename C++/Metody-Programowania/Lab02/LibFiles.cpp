#include "LibFiles.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double** f_readDataFromFile(const string filename, int rows, int cols) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku: " << filename << endl;
        return nullptr;
    }
    rows = 0;
    string line;
    while (getline(file, line)) {
        rows++;
    }

    // Powrót na pocz¹tek pliku
    file.clear();
    file.seekg(0);

    cols = 0;
    if (getline(file, line)) {
        int i = 0;
        bool isData = false;

        while (i < line.length()) {
            if (line[i] == '\t' || line[i] == ' ') {
                if (isData) {
                    isData = false;
                }
                i++;
            }
            else if ((line[i] >= '0' && line[i] <= '9') || line[i] == '.') {
                if (!isData) {
                    isData = true;
                    cols++;
                }
                i++;
            }
            else {
                i++;
            }
        }
    }

    // Powrót na pocz¹tek pliku
    file.clear();
    file.seekg(0);

    double** data = new double* [rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        if (getline(file, line)) {
            int j = 0;
            int pos = 0;

            while (j < cols && pos < line.length()) {
                // Pomijanie nowej linii i spacji
                while (pos < line.length() && (line[pos] == '\t' || line[pos] == ' ')) {
                    pos++;
                }

                // Gdy zostaje znaleziona liczba
                if (pos < line.length()) {
                    double value = 0.0;
                    bool hasDecimal = false;
                    double decimal = 1.0;

                    // Gdy zostaje znaleziona czêœæ danej tj. cyfra lub .
                    while (pos < line.length() && ((line[pos] >= '0' && line[pos] <= '9') || line[pos] == '.')) {
                        if (line[pos] == '.') {
                            hasDecimal = true;
                            pos++;
                        }
                        else if (!hasDecimal) {
                            value = value * 10.0 + (line[pos] - '0');
                            pos++;
                        }
                        else {
                            decimal *= 0.1;
                            value += (line[pos] - '0') * decimal;
                            pos++;
                        }
                    }
                    data[i][j] = value;
                    j++;
                }
            }
        }
    }

    file.close();
    return data;
}

void f_saveResultsToFile(const string filename, double* mseValues, int gridCount, int minMseIndex, double** bestGrid, int cols) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Nie mo¿na utworzyæ pliku: " << filename << endl;
        return;
    }

    file << "Wartoœci b³êdów mse dla ka¿dej z siatek:" << endl;
    for (int i = 0; i < gridCount; i++) {
        file << mseValues[i] << " ";
    }
    file << endl;

    file << "Minimalny b³¹d mse: " << mseValues[minMseIndex] << endl;

    file << "Wektor Y,X z wszystkimi danymi najlepszego dopasowania:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < cols; j++) {
            file << bestGrid[i][j] << " ";
        }
        file << endl;
    }

    file.close();
}