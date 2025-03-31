#include <iostream>
#include <fstream>
using namespace std;

/*
 * Generuje wszystkie podzia³y liczby n w porz¹dku odwrotnym do leksykograficznego i zapisuje je do pliku. Ka¿dy podzia³ jest reprezentowany jako suma liczb.
 * @param n - liczba, której podzia³y s¹ generowane.
 */
void generatePartitions(int n) {
    ofstream outFile("lab3_3d.txt");
    if (!outFile) {
        cerr << "Cannot open file." << endl;
        return;
    }

    int* s = new int[n + 1]();
    int* R = new int[n + 1]();
    s[1] = n;
    R[1] = 1;
    int d = 1;

    for (int i = 1; i <= d; i++) {
        outFile << s[i] << " ";
    }
    outFile << endl;

    while (s[1] > 1) {
        int sum = 0;
        if (s[d] == 1) {
            sum += R[d];
            d--;
        }

        sum += s[d];
        R[d]--;
        int l = s[d] - 1;
        if (R[d] > 0) {
            d++;
        }

        s[d] = l;
        R[d] = sum / l;
        l = sum % l;

        if (l != 0) {
            d++;
            s[d] = l;
            R[d] = 1;
        }

        for (int i = 1; i <= d; i++) {
            for (int j = 0; j < R[i]; j++) {
                outFile << s[i] << " ";
            }
        }
        outFile << endl;
    }

    delete[] s;
    delete[] R;
    outFile.close();
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    generatePartitions(n);
    cout << "The divisions have been saved to a file." << endl;
    return 0;
}