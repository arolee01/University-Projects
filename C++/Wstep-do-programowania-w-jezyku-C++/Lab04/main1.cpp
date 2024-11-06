#include <iostream>

using namespace std;

void zmienKolejnoscWierszy(int tablica[3][3], int wymiary) {
    for (int i = wymiary - 1; i > 0; i--) {
        for (int j = 0; j < 3; j++) {
            // swap() zmienia wartości dwóch zmiennych
            swap(tablica[i][j], tablica[i - 1][j]);
        }
    }
}

int main() {
    int tablica[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int wymiary = 3;
    
    cout << "Tablica przed zmianą wierszy: " << endl;
    
    for (int i = 0; i < wymiary; i++) {
        for (int j = 0; j < wymiary; j++) {
            cout << tablica[i][j] << " ";
        }
        cout << endl;
    }
    
    zmienKolejnoscWierszy(tablica, wymiary);

    cout << "Tablica po zmianie wierszy: " << endl;


    for (int i = 0; i < wymiary; i++) {
        for (int j = 0; j < wymiary; j++) {
            cout << tablica[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}