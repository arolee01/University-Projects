#include "ExpressionConverter.h"
#include "FileOperations.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    try {
        vector<string> lines = FileOperations::readLines("input.txt");
        vector<pair<string, string>> results;

        ExpressionConverter converter;

        for (const string& line : lines) {
            // Jeœli linia jest krótsza ni¿ 5 znaków to wyrzuca error 
            if (line.length() < 5) {
                results.push_back(make_pair(line, "Error: Za krótka linia"));
                continue;
            }

            // prefix (ONP: lub INF:)
            string prefix = line.substr(0, 4);
            // expression - wyra¿enie
            string expression = line.substr(5);

            string result;

            // Jeœli wyra¿enie jest opisane INF: to w pliku wyjœciowym opisane jest ONP:
            if (prefix == "INF:") {
                result = "ONP: " + converter.infixToONP(expression);
            }
            // Jeœli wyra¿enie jest opisane ONP: to w pliku wyjœciowym opisane jest INF:
            else if (prefix == "ONP:") {
                result = "INF: " + converter.ONPToInfix(expression);
            }
            // W przeciwnym wypadku informacja o nieznanym formacie
            else {
                result = "Error: Nieznany format";
            }

            results.push_back(make_pair(line, result));
        }

        if (!FileOperations::saveResults("output.txt", results)) {
            cerr << "B³¹d zapisu do pliku wyjœciowego" << endl;
            return 1;
        }

        cout << "Konwersja zakoñczona pomyœlnie. Wyniki zapisano w pliku output.txt" << endl;

    }
    catch (const exception& e) {
        cerr << "B³¹d: " << e.what() << endl;
        return 1;
    }

    return 0;
}