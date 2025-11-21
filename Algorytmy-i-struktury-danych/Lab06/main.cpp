#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void naiveStringMatching(string T, string P) {
    int n = T.length(); 
    int m = P.length(); 
    bool found = false;

    for (int s = 0; s <= n - m; s++) {
        int i = 0;

        while (i < m && P[i] == T[s + i]) {
            i = i + 1;
        }

        if (i == m) {
            cout << s << " ";
            found = true;
        }
    }
    if (!found) cout << "(brak)";
    cout << endl;
}



void BoyerMoore(string T, string P) {
    int n = T.length();
    int m = P.length();
    int bc[256]; 

    for (int j = 0; j < 256; j++)
        bc[j] = -1;

    for (int i = 0; i < m; i++) {
        bc[(unsigned char)P[i]] = i;
    }

    int s = 0;

    bool found = false;

    while (s <= n - m) {
        int i = m - 1;

        while (i >= 0 && P[i] == T[s + i]) {
            i = i - 1;
        }

        if (i == -1) {
            cout << s << " ";
            found = true;
            s = s + 1; 
        }
        else {
            if (bc[(unsigned char)T[s + i]] == -1) {
                s = s + i + 1;
            }
            else if (bc[(unsigned char)T[s + i]] < i) {
                s = s + i - bc[(unsigned char)T[s + i]];
            }
            else {
                s = s + 1;
            }
        }
    }
    if (!found) cout << "(brak)";
    cout << endl;
}



void RabinKarp(string T, string P) {
    int n = T.length();
    int m = P.length();
    
    int a = 256;     // liczność alfabetu (podstawa)
    int q = 101;     // modulo (liczba pierwsza)
    
    int h_p = 0;     // hash wzorca
    int h_s = 0;     // hash okna tekstu
    int h = 1;       

    for (int i = 0; i < m - 1; i++)
        h = (h * a) % q;

    for (int i = 0; i < m; i++) {
        h_p = (a * h_p + P[i]) % q;
        h_s = (a * h_s + T[i]) % q;
    }

    bool found = false;

    for (int s = 0; s <= n - m; s++) {
        
        if (h_p == h_s) {
            bool match = true; 
            for (int j = 0; j < m; j++) {
                if (T[s + j] != P[j]) {
                    match = false;
                    break;
                }
            }
            
            if (match) {
                cout << s << " ";
                found = true;
            }
        }

        if (s < n - m) {
            h_s = (a * (h_s - T[s] * h) + T[s + m]) % q;

            if (h_s < 0)
                h_s = (h_s + q);
        }
    }
    if (!found) cout << "(brak)";
    cout << endl;
}

string textGenerator(int n) {
    string t = "";
    static const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < n; i++) {
        t += alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    return t;
}

int main() {
    srand(time(NULL));

    // Testy na danych z polecenia
    string T = "gfrgfgigjmgfrrogirgfrgfrgfrgirhgrygfrgfygirmggfrgfgfrgffeutyitbhfuvwgfrgf";
    string P = "gfrgf";

    cout << "### ZADANIE 1: Naiwny ###" << endl;
    naiveStringMatching(T, P);

    cout << "\n### ZADANIE 2: Boyer-Moore ###" << endl;
    BoyerMoore(T, P);

    cout << "\n### ZADANIE 3: Rabin-Karp ###" << endl;
    RabinKarp(T, P);

    // Zadanie 4 - eksperyment czasowy
    cout << "\n### ZADANIE 4: Porownanie czasowe ###" << endl;
    int test_n = 500000;
    string randT = textGenerator(test_n);
    string randP = textGenerator(4);
    
    clock_t start;
    double time_naive, time_bm, time_rk;

    start = clock();
    naiveStringMatching(randT, randP);
    time_naive = (double)(clock() - start) / CLOCKS_PER_SEC;

    start = clock();
    BoyerMoore(randT, randP);
    time_bm = (double)(clock() - start) / CLOCKS_PER_SEC;

    start = clock();
    RabinKarp(randT, randP);
    time_rk = (double)(clock() - start) / CLOCKS_PER_SEC;

    cout << "\nCzas Naiwny: " << time_naive << "s" << endl;
    cout << "Czas Boyer-Moore: " << time_bm << "s" << endl;
    cout << "Czas Rabin-Karp: " << time_rk << "s" << endl;

    return 0;
}