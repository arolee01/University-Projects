/*
* Dla tablicy z haszowaniem przechowującej elementy z kluczem tekstowym(string) proszę zaimplementować wskazane w szablonie operacje.Proszę zastosować metodę próbkowanie liniowego do rozwiązania problemu kolizji.Proszę przetestować poprawność działania operacji.Testy powinny być zaprezentowane w sposób czytelny i jednoznaczny.

Szablon rozwiązania :

//Zadanie 1
class HashTable {
private:
    string* t;
    int capacity;
    int size;
public:
    HashTable(int c);                //konstruktor tworzący pustą tablicę o pojemności c
    bool empty();
    bool full();
    int hashFunction(string s);        //funkcja haszująca dla klucza s
    void insert(string d);            //wstawienie  dane d z kluczem s (w tym przypadku s = d)
    int insert1(string d);            //wstawienie dane d z kluczem s (zwraca liczbę prób przy wystąpieniu kolizji - 0 jeśli kolizja nie wystąpiła)
    void del(string s);                //usuwa element z kluczem s
    string search(string s);        //wyszukuje i zwraca element z kluczem s
    int search1(string s);            //wyszukuje element z kluczem s i zwraca liczbę prób przy wystąpieniu kolizji - 0 jeśli kolizja nie wystąpiła
    friend ostream& operator<<(ostream& out, HashTable& ht); //wypisuje tablicę (z numerami pól), pozostawia puste dla wolnych pól

};

Zadanie 2:

Wykorzystując tablicę z haszowaniem z zadania 1 proszę wykonać eksperyment umożliwiający sprawdzenie:

jak często pojawiając się kolizje, przy wstawianiu/wyszukiwaniu oraz

ile prób wymaga wstawienie/wyszukanie pojedynczego klucza ,

jak współczynnik zapełnienia tablicy wpływa na częstotliwość pojawiania się kolizji i liczbę prób przy wstawianiu klucza

Szablon rozwiązania:

//Zadanie 2 - test
cout<<"Zadanie 2 - test"<<endl;
{
int n=...;                // pojemność tablicy z haszowaniem, do przetestowania różne wartości
string* dane = new string[n]{.....}; //tablica do przechowania danych do testowania, można je odczytać z pliku lub zainicjalizować nimi tablicę
// ....
}

Przykładowe dane do testowania:

Julia
Zuzanna
Zofia
Lena
Maja
Hanna
Amelia
Alicja
Maria
Aleksandra
Oliwia
Natalia
Wiktoria
Emilia
Antonina
Laura
Pola
Iga
Anna
Liliana
Antoni
Jakub
Jan
Szymon
Franciszek
Filip
Aleksander
Mikolaj
Wojciech
Kacper
Adam
Michal
Marcel
Stanislaw
Wiktor
Piotr
Igor
Leon
Nikodem
Mateusz
*/

#include <iostream>
#include <string>

using namespace std;

class HashTable {
private:
    string* t;
    int capacity;
    int size;
public:
    // Konstruktor tworzący pustą tablicę o pojemności c
    HashTable(int c) {
        capacity = c;
        size = 0;
        t = new string[capacity];
        for (int i = 0; i < capacity; i++) {
            t[i] = "";
        }
    }                   
    bool empty() {
        return size == 0;
    }
    bool full() {
        return size == capacity;
    }
    
    // Funkcja haszująca dla klucza s
    int hashFunction(string s) { 
        unsigned int hash = 0;
        for (char c : s) {
            hash += c;
        }
        return hash % capacity;
    }
    
    // Wstawienie dane d z kluczem s (w tym przypadku s = d)
    void insert(string d) {
        if (full()) {
            cout << "Tablica jest pełna" << endl;
            return;
        }
        int index = hashFunction(d);
        while (!t[index].empty()) {
            index = (index + 1) % capacity;
        }
        t[index] = d;
        size++;
    }     
    
    // Wstawienie dane d z kluczem s (zwraca liczbę prób przy wystąpieniu kolizji 
    // - 0 jeśli kolizja nie wystąpiła)
    int insert1(string d) {
        if (full()) {
            cout << "Tablica jest pełna" << endl;
            return -1;
        }
        int index = hashFunction(d);
        int attempts = 0;
        while (!t[index].empty()) {
            index = (index + 1) % capacity;
            attempts++;
        }
        t[index] = d;
        size++;
        return attempts;
    } 
    
    // Usuwa element z kluczem s
    void del(string s) {
        int index = hashFunction(s);
        int startIndex = index;
    
        while (!t[index].empty()) {
            if (t[index] == s) {
                t[index] = "";
                size--;
    
                index = (index + 1) % capacity;
                while (!t[index].empty()) {
                    string temp = t[index];
                    t[index] = "";
                    size--;
                    insert(temp);
                    index = (index + 1) % capacity;
                }
                return;
            }
            index = (index + 1) % capacity;
            if (index == startIndex) break;
        }
        cout << "Element " << s << " nie znaleziony." << endl;
    }         
    
    // Wyszukuje i zwraca element z kluczem s
    string search(string s) {
        int index = hashFunction(s);
        int startIndex = index;
        while (!t[index].empty()) {
            if (t[index] == s) {
                return t[index];
            }
            index = (index + 1) % capacity;
            if (index == startIndex) break; 
        }
        return "";
    }            
    
    // Wyszukuje element z kluczem s i zwraca liczbę prób przy 
    // wystąpieniu kolizji - 0 jeśli kolizja nie wystąpiła
    int search1(string s) {
        int index = hashFunction(s);
        int startIndex = index;
        int attempts = 0;
        while (!t[index].empty()) {
            if (t[index] == s) {
                return attempts;
            }
            index = (index + 1) % capacity;
            attempts++;
            if (index == startIndex) break; 
        }
        return -1; 
    }              
    
    // Wypisuje tablicę (z numerami pól), pozostawia puste dla wolnych pól
    friend ostream& operator<<(ostream& out, HashTable& ht) {
    	out << "Tablica z haszowaniem:" << endl;
        for (int i = 0; i < ht.capacity; i++) {
            out << i << ": ";
            if (ht.t[i].empty()) {
                out << " " << endl;
            } else {
                out << ht.t[i] << endl;
    		}
        }
        out << endl;
        return out;
    } 
};

int main() {
	HashTable ht(10);

	ht.insert("jablko");
	ht.insert("banan");
	ht.insert1("pomarancza");
	ht.insert1("gruszka");
    ht.insert1("gruszka");
    ht.insert1("gruszka");
    ht.insert1("gruszka");

    cout << "Liczba kolizji, ktore wystapily przy ht.insert1('gruszka'): " << ht.insert1("gruszka") << endl;

    cout << ht;
	ht.del("gruszka");
    
    cout << ht;
	string wynik = ht.search("banan");
	cout << "Wynik wyszukiwania 'banan': " << wynik << endl;
    wynik = ht.search("pomarancza");
    cout << "Wynik wyszukiwania 'pomarancza': " << wynik << endl;
	int proby = ht.search1("pomarancza");
	cout << "Liczba prob przy wyszukiwaniu 'pomarancza': " << proby << endl;

    return 0;
}