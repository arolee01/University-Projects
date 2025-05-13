#include "generator.h"
#include <fstream>
#include <stdexcept>

using namespace std;

vector<int> generateLCG(int a, int c, int m, int seed, int n) {
    vector<int> numbers;
    int x = seed;

    for (int i = 0; i < n; ++i) {
        x = (a * x + c) % m;
        numbers.push_back(x+1);
    }
    return numbers;
}

vector<int> generateAdditive(int m, int n) {
    const vector<int> initialValues = { 2, 5, 1, 7, 4, 3 };
    const int j = 2, k = 5;

    vector<int> Y = initialValues;
    vector<int> output;
    int size = Y.size();

    for (int i = 0; i < n; ++i) {
        Y[k - 1] = (Y[j - 1] + Y[k - 1]) % m;
        output.push_back(Y[k - 1]);
    }
    return output;
}

void saveToFile(const vector<int>& numbers, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Nie mo¿na otworzyæ pliku do zapisu");
    }

    for (int num : numbers) {
        file << num << "\n";
    }
    file.close();
}