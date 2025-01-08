#include <iostream>
using namespace std;

class Zwierze {
protected:
    string imie;
public:
    Zwierze() :imie("brak") {}
    Zwierze(const string& i) :imie(i) {}
    virtual void info() const {
        cout << "Mam na imie " << imie << endl;
    }
};

class Pies :public Zwierze {
    string rasa;
public:
    Pies()
        : Zwierze(), rasa("kundelek") {
    }
    Pies(const string& i, const string& r)
        :Zwierze(i), rasa(r) {
    }
    void wyswietl_rase() const {
        cout << "Moja rasa " << rasa << endl;
    }
    void info() const override { // dodane const override
        Zwierze::info();
        cout << "Moja rasa " << rasa << endl;
    }
};

int main()
{
    Pies pies("Burek", "Mieszaniec");
    pies.info();
    pies.wyswietl_rase();

    cout << "--------------------------\n";

    Zwierze zwierz1 = pies;
    zwierz1.info(); // Wyœwietla tylko, "Mam na imiê Burek", obcina rasê
    //zwierz1.wyswietl_rase(); // wyswietl_rase nie jest metod¹ klasy Zwierze, wyœwietla b³¹d

    cout << "--------------------------\n";

    Zwierze* zwierz2 = &pies;
    zwierz2->info(); // Wyœwietla tylko, "Mam na imiê Burek", rasa nie jest argumentem klasy Zwierze, po zmianie kodu wyœwietla i imiê i rasê
    //zwierz2->wyswietl_rase(); // wyswietl_rase nie jest metod¹ klasy Zwierze, wyœwietla b³¹d

    cout << "--------------------------\n";

    zwierz2 = &zwierz1;
    zwierz2->info(); // Wyœwietla tylko, "Mam na imiê Burek", rasa nie jest argumentem klasy Zwierze

    return 0;
}

/*
Wynik dzia³ania kodu:

Mam na imie Burek
Moja rasa Mieszaniec
Moja rasa Mieszaniec
--------------------------
Mam na imie Burek
--------------------------
Mam na imie Burek
Moja rasa Mieszaniec
--------------------------
Mam na imie Burek

*/