#include <iostream>
#include <string>
#include "LibFiles.h"
#include "LibTables.h"
#include "LibMSE.h"

using namespace std;

int main() {
    string seakFilename, nmSeakFilename, sebFilename, nmSebFilename, seakResultFilename, sebResultFilename;

    cout << "Podaj nazwê pliku z siatkami silnika asynchronicznego klatkowego (np. siatkaSEAK.txt): ";
    cin >> seakFilename;
    cout << "Podaj nazwê pliku z nieznanym modelem silnika asynchronicznego klatkowego (np. nmSEAK.txt): ";
    cin >> nmSeakFilename;
    cout << "Podaj nazwê pliku wyjœciowego dla silnika asynchronicznego klatkowego (np. SEAK_wyniki.txt): ";
    cin >> seakResultFilename;

    cout << "Podaj nazwê pliku z siatkami silnika bezszczotkowego (np. siatkaSEB.txt): ";
    cin >> sebFilename;
    cout << "Podaj nazwê pliku z nieznanym modelem silnika bezszczotkowego (np. nmSEB.txt): ";
    cin >> nmSebFilename;
    cout << "Podaj nazwê pliku wyjœciowego dla silnika bezszczotkowego (np. SEB_wyniki.txt): ";
    cin >> sebResultFilename;


    f_processMotorModel(seakFilename, nmSeakFilename, seakResultFilename, "asynchroniczny klatkowy");
    f_processMotorModel(sebFilename, nmSebFilename, sebResultFilename, "bezszczotkowy");

    cout << "Program zakoñczy³ dzia³anie. Wyniki zapisano do plików " << seakResultFilename << " i " << sebResultFilename << endl;

    return 0;
}