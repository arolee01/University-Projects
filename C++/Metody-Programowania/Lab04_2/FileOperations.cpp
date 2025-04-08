#include "FileOperations.h"
#include <fstream>
#include <stdexcept>

using namespace std;

vector<string> FileOperations::readLines(const string& filename) {
    vector<string> lines;
    ifstream file(filename);

    if (!file.is_open()) {
        throw ("Nie mo¿na otworzyæ pliku wejœciowego: " + filename);
    }

    string line;

    if (getline(file, line)) {
        int numExpressions;
        try {
            numExpressions = stoi(line);
        }
        catch (...) {
            throw ("Nieprawid³owy format pliku wejœciowego: pierwsza linia powinna byæ liczb¹ ca³kowit¹");
        }

        while (getline(file, line) && lines.size() < numExpressions) {
            lines.push_back(line);
        }
    }

    file.close();
    return lines;
}

bool FileOperations::saveResults(const string& filename, const vector<pair<string, string>>& results) {
    ofstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    for (const auto& result : results) {
        file << result.second << endl;
    }

    file.close();
    return true;
}