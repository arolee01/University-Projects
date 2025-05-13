#include <iostream>
#include "generator.h"
#include "menu.h"

using namespace std;

int main() {
    // Liszka Arkadiusz

    try {
        int choice = showMenu();

        if (choice == 1) {
            int a, c, m, seed, n;
            getLCGParams(a, c, m, seed, n);
            vector<int> numbers = generateLCG(a, c, m, seed, n);
            saveToFile(numbers, "OutputLinearCongruentalMethod.txt");
            cout << "Wynik zapisano do OutputLinearCongruentalMethod.txt\n";
        }
        else if (choice == 2) {
            int m, n;
            getAdditiveParams(m, n);
            vector<int> numbers = generateAdditive(m, n);
            saveToFile(numbers, "OutputAdditiveCongruentalMethod.txt");
            cout << "Wynik zapisano do OutputAdditiveCongruentalMethod.txt\n";
        }
        else {
            cout << "Nieprawidlowy wybor!\n";
        }
    }
    catch (const exception& e) {
        cerr << "Blad: " << e.what() << endl;
        return 1;
    }
    return 0;
}