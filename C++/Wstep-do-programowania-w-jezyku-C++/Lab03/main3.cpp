#include <iostream>

using namespace std;

string tekst;

string rozdzielLitery(string tekst) {
    string napiskoncowy;
    
    // jeśli dany znak w tekście nie jest spacją, to dodaje po nim spację
    for(char litera : tekst) {
        if (litera !=' ') {
            napiskoncowy += litera;
            napiskoncowy += ' ';
        }
    }
    
    // usuwa spacje z ostatniego pola (jeśli jest)
    if (!napiskoncowy.empty()) {
        napiskoncowy.pop_back();
    }
    return napiskoncowy;
} 

int main() {
    cout << "Podaj tekst: " << endl;
    getline(cin, tekst);
    cout << "Wprowadzony teskt: \n" << tekst << endl;
    cout << "Tekst po użyciu funkcji: \n" << rozdzielLitery(tekst) << endl;
    
}