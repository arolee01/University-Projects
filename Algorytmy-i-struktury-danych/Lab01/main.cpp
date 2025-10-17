/******************************************************************************

Lista – reprezentacja tablicowa

Zadanie 1:

Dla listy reprezentowanej w oparciu o tablicę proszę zaimplementować wskazane w szablonie operacje. Proszę przetestować poprawność ich działania – testy powinny być opracowane w taki sposób, aby weryfikowały działanie operacji we wszystkich możliwych do zaistnienia przypadkach. Testy powinny być zaprezentowane w sposób czytelny i jednoznaczny.

Szablon rozwiązania:

class ArrayList{
    private:
        int *items;
        int head;                    //pozycja pierwszego elementu
        int tail;                    //pozycja ostatniego elementu
        int capacity;                 //rozmiar tablicy
        int size;                    //długość listy (liczba elementów w liście)
    
    public:
        ArrayList(int c);            //tworzy pustą pistę o pojemności c
        bool empty();                //zwraca prawdę jeśli lista pusta, fałsz w przeciwnym przypadku
        bool full();                //zwraca prawdę jeśli lista jest pełna, fałsz w przeciwnym przypadku
        int getSize();                //zwraca wielkość listy (liczbę elementów w liście)
        int getCapacity();            //zwraca pojemnośc listy (rozmiar tablicy)
        int getFirst();              //zwraca pozycję pierwszego elementu
        int getLast();               //zwraca pozycję ostatniego elementu
        int getNext(int p);            //zwraca pozycję elementu następnego za p
        int getPrev(int p);            //zwraca pozycję elementu poprzedzającego p
        int retrieve(int p);         //zwraca element (wartość) z pozycji p
        void append(int x);            //wstawia element x na końcu listy
        void preppend(int x);            //wstawia element x na początku listy
        friend ostream& operator<<(ostream& out, ArrayList& l); //wypisuje elementu listy   
        ~ArrayList();
};

//Zadanie 1 - przykładowy sposób testowania 
ArrayList a(5);
cout << endl <<"empty(): 1 - "<<a.empty();
cout<<endl<<"full(): 0 - "<<a.full();
cout<<endl<<"append(4): 4 - "; a.append(4); cout<<" "<<a;
//...

Zadanie 2:

Do klasy z zadania 1 proszę dodać wskazane w szablonie operacje oraz zaimplementować je i przetestować poprawności ich działania w możliwych do zaistnienia przypadkach. Testy powinny być zaprezentowane w sposób czytelny i jednoznaczny.

Szablon rozwiązania:

klasa ArrayList:


        void insert(int p, int x);     //wstawia element x na pozycję p (operacja tylko dla istniejących pozycji)
        void del(int p);              //usuwa element z pozycji p  (operacja tylko dla istniejących pozycji)  
        void clear();                //usuwa całą zawartość listy

Zadanie 3:

Do klasy z zadania 1 i 2 proszę dodać wskazane w szablonie operacje oraz zaimplementować je i przetestować poprawności ich działania w możliwych do zaistnienia przypadkach. Testy powinny być zaprezentowane w sposób czytelny i jednoznaczny.

Szablon rozwiązania:

klasa ArrayList:
 

    int locate(int x);          //zwrac pozycję pierwszego wystąpienia elementu x, -1 jeśli x nie występuje
    void deleteX(int x);              //usuwa pierwsze wystąpienie elementu o wartości x
    void deleteAllX(int x);            //usuwa wszystkie wystąpienia elementu o wartości x

Zadanie 4:

Proszę utworzyć klasę SortedArrayList. Dla klasy SortedArrayList 
proszę zaimplementować operację umożliwiającą dodanie elementu x 
z zachowaniem porządku niemalejącego. Proszę przetestować poprawności 
działania w/w operacji w możliwych do zaistnienia przypadkach. 
Testy powinny być zaprezentowane w sposób czytelny i jednoznaczny.

Szablon rozwiązania:

class SortedArrayList{
    private:
        int *items;
        int head;                    //pozycja pierwszego elementu
        int tail;                    //pozycja ostatniego elementu
        int capacity;                 //rozmiar tablicy
        int size;                    //długość listy (liczba elementów w liście)
    
    public:
        //konstruktor, destruktor, inne wymagane operacje
        void insertSorted(int x);                //wstawia element x z zachowaniem porządku niemalejącego
};   

Uwaga do zadania 4

Wstawienie elementu z zachowaniem porządku niemalejącego oznacza, 
że funkcja insertSorted() znajduje właściwe miejsce, uwzględniając 
istniejący porządek, i wstawia na nie element.
*******************************************************************************/
#include <iostream>

using namespace std;

class ArrayList {
    private:
        int *items;
        int head;
        int tail;
        int capacity;
        int size;

    public:
        ArrayList(int c) {
            capacity = c;
            items = new int[c];
            size = 0;
            head = -1;
            tail = -1;
        }

        ~ArrayList() {
            delete[] items;
        }

        bool empty() {
            return size == 0;
        }

        bool full() {
            return size == capacity;
        }

        int getSize() {
            return size;
        }

        int getCapacity() {
            return capacity;
        }

        int getFirst() {
            return head;
        }

        int getLast() {
            return tail;
        }

        int getNext(int p) {
            if (p >= tail || p < head) return -1;
            return p + 1;
        }

        int getPrev(int p) {
            if (p <= head || p > tail) return -1;
            return p - 1;
        }

        int retrieve(int p) {
            if (p < head || p > tail || empty()) {
                return -1; 
            }
            return items[p];
        }

        void append(int x) {
            if (full()) {
                cout << "Blad: Lista pelna (append)" << endl;
                return;
            }
            
            if (empty()) {
                head = 0;
                tail = 0;
            } else {
                tail++;
            }
            
            items[tail] = x;
            size++;
        }

        void preppend(int x) {
            if (full()) {
                cout << "Blad: Lista pelna (preppend)" << endl;
                return;
            }

            if (empty()) {
                head = 0;
                tail = 0;
                items[0] = x;
            } else {
                for (int i = tail; i >= head; i--) {
                    items[i + 1] = items[i];
                }
                items[head] = x;
                tail++;
            }
            size++;
        }

        friend ostream& operator<<(ostream& out, ArrayList& l) {
            out << "[ ";
            for (int i = l.head; i <= l.tail; i++) {
                out << l.items[i] << " ";
            }
            out << "]";
            
            return out;
        }
        
        void insert(int p, int x) {
            if (full()) {
                cout << "Lista pelna (insert)" << endl;
                return;
            }
            if (p < head || p > tail) {
                cout << "Nieprawidlowa pozycja (insert)" << endl;
                return;
            }
        
            for (int i = tail; i >= p; i--) {
                items[i + 1] = items[i];
            }
        
            items[p] = x;
            tail++;
            size++;
        }

        void del(int p) {
            if (empty()) {
                cout << "Lista pusta (del)" << endl;
                return;
            }
            
            if (p < head || p > tail) {
                cout << "Nieprawidlowa pozycja (del)" << endl;
                return;
            }
            
            // Przesuwanie elementów w lewo, aby zapełnić lukę po usuniętym elemencie
            for (int i = p; i < tail; i++) {
                items[i] = items[i + 1];
            }
            
            tail--;
            size--;
            
            // Jeśli usunęliśmy ostatni element, resetujemy wskaźniki dla porządku
            if (size == 0) {
                head = -1;
                tail = -1;
            }
        }
    
        void clear() {
            head = -1;
            tail = -1;
            size = 0;
        }
        
        int locate(int x) {
            if (empty()) return -1;
            for (int i = head; i <= tail; i++) {
                if (items[i] == x) {
                    return i;
                }
            }
            return -1;
        }
        
        void deleteX(int x) {
            int p = locate(x);
            if(p != -1) {
                del(p);
            }
        }
        
        void deleteAllX(int x) {
            if (empty()) return;
            
            int i = head;
            while (i <= tail && i != -1) {
                if (items[i] == x) {
                    del(i);
                } else {
                    i++;
                }
            }
        }
        
        
};

class SortedArrayList {
    private:
        int *items;
        int head;
        int tail;
        int capacity;
        int size;
    
    public:
        SortedArrayList(int c) {
            capacity = c;
            items = new int[c];
            size = 0;
            head = -1;
            tail = -1;
        }

        ~SortedArrayList() {
            delete[] items;
        }

        bool empty() { return size == 0; }
        bool full() { return size == capacity; }
        int getSize() { return size; }

        void insertSorted(int x) {
            if (full()) {
                cout << "Blad: Lista pelna (insertSorted)" << endl;
                return;
            }

            if (empty()) {
                head = 0;
                tail = 0;
                items[0] = x;
                size++;
                return;
            }

            // Lista niepusta
            // Krok A: Znajdź miejsce wstawienia (pierwszy element większy od x)
            int i = head;
            while (i <= tail && items[i] < x) {
                i++;
            }
            // Zmienna 'i' wskazuje teraz indeks, gdzie powinien trafić 'x'

            // Krok B: Przesuń elementy od 'tail' do 'i' w prawo
            for (int j = tail; j >= i; j--) {
                items[j + 1] = items[j];
            }

            // Krok C: Wstaw element i zaktualizuj wskaźniki
            items[i] = x;
            tail++;
            size++;
        }

        friend ostream& operator<<(ostream& out, SortedArrayList& l) {
            out << "[ ";
            for (int i = l.head; i <= l.tail; i++) out << l.items[i] << " ";
            out << "]";
    
            return out;
        }
};

int main() {
    cout << "=== ZADANIE 1 - TESTY ===" << endl;

    // 1. Test tworzenia pustej listy
    ArrayList a(5);
    cout << "1. Nowa lista (pojemosc 5):" << endl;
    cout << "   empty() (oczekiwane 1): " << a.empty() << endl;
    cout << "   full()  (oczekiwane 0): " << a.full() << endl;
    cout << "   size    (oczekiwane 0): " << a.getSize() << endl;
    cout << "   Wydruk: " << a << endl;

    // 2. Test append (dodawanie na koniec)
    cout << endl << "2. Append (dodajemy 10, 20, 30):" << endl;
    a.append(10);
    a.append(20);
    a.append(30);
    cout << "   Wydruk: " << a << endl;
    cout << "   First indeks: " << a.getFirst() << " (wartosc: " << a.retrieve(a.getFirst()) << ")" << endl;
    cout << "   Last indeks:  " << a.getLast() << " (wartosc: " << a.retrieve(a.getLast()) << ")" << endl;

    // 3. Test preppend (dodawanie na poczatek)
    cout << endl << "3. Preppend (dodajemy 5 na poczatek):" << endl;
    a.preppend(5);
    cout << "   Wydruk: " << a << endl; // Oczekiwane: [ 5 10 20 30 ]
    cout << "   First indeks: " << a.getFirst() << " (wartosc: " << a.retrieve(a.getFirst()) << ")" << endl;

    // 4. Test nawigacji (Next/Prev)
    cout << endl << "4. Nawigacja:" << endl;
    int current = a.getFirst();
    int next = a.getNext(current);
    cout << "   Element po indeksie " << current << " to indeks " << next 
         << " o wartosci " << a.retrieve(next) << endl;
    
    int last = a.getLast();
    int prev = a.getPrev(last);
    cout << "   Element przed indeksem " << last << " to indeks " << prev 
         << " o wartosci " << a.retrieve(prev) << endl;

    // 5. Test zapelnienia listy (Full)
    cout << endl << "5. Zapelnianie listy:" << endl;
    a.append(40); // Lista ma teraz 5 elementów (5, 10, 20, 30, 40)
    cout << "   Wydruk: " << a << endl;
    cout << "   full() (oczekiwane 1): " << a.full() << endl;

    // 6. Test przepelnienia (Overflow)
    cout << endl << "6. Proba dodania do pelnej listy:" << endl;
    cout << "   Akcja: "; 
    a.append(50); // Powinien wyswietlic blad
    cout << "   Rozmiar po probie: " << a.getSize() << endl;
    
    cout << "=== ZADANIE 2 - TESTY ===" << endl;

    // Przygotowanie listy
    ArrayList b(10); // Pojemność 10
    b.append(10);
    b.append(20);
    b.append(30);
    b.append(40);
    cout << "Stan poczatkowy: " << b << endl; // [ 10 20 30 40 ]

    // --- TEST INSERT ---
    cout << endl << "1. Test insert(p, x):" << endl;
    
    // Wstawienie w środek (na indeks 1, czyli zamiast 20)
    cout << "   insert(1, 99) -> Wstawiamy 99 na pozycje 1." << endl;
    b.insert(1, 99);
    cout << "   Wynik: " << b << endl; // Oczekiwane: [ 10 99 20 30 40 ]
    
    // Wstawienie na początek (indeks 0) - alternatywa dla preppend
    cout << "   insert(0, 5)  -> Wstawiamy 5 na pozycje 0." << endl;
    b.insert(0, 5); 
    cout << "   Wynik: " << b << endl; // Oczekiwane: [ 5 10 99 20 30 40 ]

    // Próba wstawienia na nieistniejącą pozycję
    cout << "   insert(50, 7) -> Proba bledna." << endl;
    b.insert(50, 7); 

    // --- TEST DEL ---
    cout << endl << "2. Test del(p):" << endl;
    
    // Usunięcie ze środka (indeks 2, wartość 99)
    cout << "   del(2) -> Usuwamy element z indeksu 2 (byl to 99)." << endl;
    b.del(2);
    cout << "   Wynik: " << b << endl; // Oczekiwane: [ 5 10 20 30 40 ]

    // Usunięcie z końca (indeks 4, wartość 40)
    int lastIndex = b.getLast();
    cout << "   del(" << lastIndex << ") -> Usuwamy ostatni element." << endl;
    b.del(lastIndex);
    cout << "   Wynik: " << b << endl; // Oczekiwane: [ 5 10 20 30 ]

    // --- TEST CLEAR ---
    cout << endl << "3. Test clear():" << endl;
    b.clear();
    cout << "   Po clear(): " << b << endl;
    cout << "   Czy pusta? " << (b.empty() ? "TAK" : "NIE") << endl;
    cout << "   Rozmiar: " << b.getSize() << endl;

    // Sprawdzenie czy po clear można normalnie używać listy
    cout << "   Ponowne dodanie elementu append(100):" << endl;
    b.append(100);
    cout << "   Wynik: " << b << endl;
    
    cout << "=== ZADANIE 3 - TESTY (Lista c) ===" << endl;
    
    ArrayList c(15); // Większa pojemność dla testów

    // Przygotowanie danych testowych (z duplikatami)
    c.append(10);
    c.append(20);
    c.append(5);
    c.append(20);
    c.append(30);
    c.append(20);
    c.append(40);

    cout << "1. Stan poczatkowy listy c: " << endl;
    cout << "   " << c << endl; // Oczekiwane: [ 10 20 5 20 30 20 40 ]

    // --- TEST locate(x) ---
    cout << endl << "2. Test locate(x):" << endl;
    int val1 = 20;
    int val2 = 99;
    
    cout << "   Szukam wartosci " << val1 << "..." << endl;
    int pos1 = c.locate(val1);
    cout << "   Wynik: indeks " << pos1 << " (oczekiwany: 1)" << endl;

    cout << "   Szukam wartosci " << val2 << "..." << endl;
    int pos2 = c.locate(val2);
    cout << "   Wynik: indeks " << pos2 << " (oczekiwany: -1)" << endl;

    // --- TEST deleteX(x) ---
    cout << endl << "3. Test deleteX(x):" << endl;
    
    cout << "   a) deleteX(5) - usuwanie elementu unikalnego" << endl;
    c.deleteX(5);
    cout << "      Wynik: " << c << endl; // Oczekiwane: brak 5

    cout << "   b) deleteX(20) - usuwanie pierwszego wystapienia duplikatu" << endl;
    c.deleteX(20);
    cout << "      Wynik: " << c << endl; // Oczekiwane: pierwsze 20 znika, reszta zostaje

    cout << "   c) deleteX(99) - proba usuniecia elementu nieistniejacego" << endl;
    c.deleteX(99);
    cout << "      Wynik: " << c << " (bez zmian)" << endl;

    // --- TEST deleteAllX(x) ---
    cout << endl << "4. Test deleteAllX(x):" << endl;
    cout << "   Aktualny stan: " << c << endl;
    cout << "   Usuwam wszystkie wystapienia 20..." << endl;
    
    c.deleteAllX(20);
    
    cout << "   Wynik: " << c << endl; // Oczekiwane: żadnego 20 w liście
    
    // Dodatkowy test na deleteAllX, gdy elementy są obok siebie
    c.clear();
    c.append(7);
    c.append(7);
    c.append(7);
    cout << endl << "   Test dodatkowy (same siodemki): " << c << endl;
    c.deleteAllX(7);
    cout << "   Po deleteAllX(7): " << c << endl;
    
    // ==========================================
    // TESTY ZADANIA 4 (SortedArrayList d)
    // ==========================================
    cout << endl << "=== ZADANIE 4 - TESTY (SortedArrayList d) ===" << endl;
    
    SortedArrayList d(10); // Pojemność 10

    // 1. Test na pustej liście
    cout << "1. Wstawiam 50 (do pustej):" << endl;
    d.insertSorted(50);
    cout << "   Wynik: " << d << endl;

    // 2. Test wstawiania elementu mniejszego (na początek)
    cout << endl << "2. Wstawiam 20 (mniejsze od 50):" << endl;
    d.insertSorted(20);
    cout << "   Wynik: " << d << endl; // Oczekiwane: [ 20 50 ]

    // 3. Test wstawiania elementu większego (na koniec)
    cout << endl << "3. Wstawiam 80 (wieksze od 50):" << endl;
    d.insertSorted(80);
    cout << "   Wynik: " << d << endl; // Oczekiwane: [ 20 50 80 ]

    // 4. Test wstawiania elementu w środek
    cout << endl << "4. Wstawiam 40 (pomiedzy 20 a 50):" << endl;
    d.insertSorted(40);
    cout << "   Wynik: " << d << endl; // Oczekiwane: [ 20 40 50 80 ]

    // 5. Test duplikatów (zachowanie porządku niemalejącego)
    cout << endl << "5. Wstawiam 50 (duplikat):" << endl;
    d.insertSorted(50);
    cout << "   Wynik: " << d << endl; // Oczekiwane: [ 20 40 50 50 80 ]

    // 6. Test dużej liczby elementów
    cout << endl << "6. Uzupelniam kolejnymi liczbami:" << endl;
    d.insertSorted(10);
    d.insertSorted(35);
    d.insertSorted(90);
    cout << "   Wynik: " << d << endl;

    // 7. Test przepełnienia (opcjonalny)
    // d ma pojemność 10. Mamy teraz 8 elementów. Dodajmy 3.
    d.insertSorted(1);
    d.insertSorted(2);
    cout << "   Przed przepelnieniem: " << d << " (rozmiar: " << d.getSize() << ")" << endl;
    cout << "   Proba dodania 11-go elementu:" << endl;
    d.insertSorted(100); // Powinien być błąd

    return 0;
}