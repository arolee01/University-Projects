#include <iostream>

using namespace std;

class Element {
private:
    int p; 
    char v; 
public:
    Element() : p(0), v(0) {}
    Element(int p, char z) : p(p), v(z) {}

    int getP() { return p; }
    char getV() { return v; }
    void setP(int p) { this->p = p; }
    void setV(char v) { this->v = v; }

    bool operator==(const Element &e) { return this->p == e.p; }
    bool operator>(const Element &e) { return this->p > e.p; }
    bool operator>=(const Element &e) { return this->p >= e.p; }
    bool operator<(const Element &e) { return this->p < e.p; }
    bool operator<=(const Element &e) { return this->p <= e.p; }

    friend ostream& operator<<(ostream& out, const Element& e);
};

ostream& operator<<(ostream& out, const Element& e) {
    out << "[" << e.p << ", " << e.v << "]";
    return out;
}

class Heap {
private:
    Element* kopiec;
    int capacity;
    int size;

public:
    Heap(int c) {
        capacity = c;
        size = 0;
        kopiec = new Element[capacity];
    }

    Heap() {
        capacity = 15;
        size = 12;
        kopiec = new Element[capacity];

        kopiec[0] = Element(15, 'a');
        kopiec[1] = Element(9, 'b');
        kopiec[2] = Element(12, 'd');
        kopiec[3] = Element(9, 'f');
        kopiec[4] = Element(7, 'g');
        kopiec[5] = Element(5, 'h');
        kopiec[6] = Element(10, 'x');
        kopiec[7] = Element(4, 'y');
        kopiec[8] = Element(3, 'z');
        kopiec[9] = Element(3, 'z');
        kopiec[10] = Element(2, 'z');
        kopiec[11] = Element(4, 'z');
    }

    ~Heap() {
        delete[] kopiec;
    }

    bool empty() { return size == 0; }
    bool full() { return size == capacity; }

    int getLeft(int i) {
        int leftIndex = 2 * i + 1;
        if (leftIndex >= size) return -1;
        return leftIndex;
    }

    int getRight(int i) {
        int rightIndex = 2 * i + 2;
        if (rightIndex >= size) return -1;
        return rightIndex;
    }

    int getParent(int i) {
        if (i <= 0) return -1;
        return (i - 1) / 2;
    }

    int getSize() {
        return size;
    }

    void setSize(int s) {
        if (s > capacity) size = capacity;
        else if (s < 0) size = 0;
        else size = s;
    }

    Element getValue(int i) {
        if (i >= 0 && i < size) return kopiec[i];
        return Element(); 
    }

    int getPriority(int i) {
        if (i >= 0 && i < size) return kopiec[i].getP();
        return -1; 
    }

    void setValue(int i, Element x) {
        if (i >= 0 && i < size) {
            kopiec[i] = x;
        }
    }

    void bottomUp(int i) {
        if (i > 0) {
            int p = getParent(i);
            if (p != -1 && kopiec[i] > kopiec[p]) {
                Element temp = kopiec[i];
                kopiec[i] = kopiec[p];
                kopiec[p] = temp;
                bottomUp(p);
            }
        }
    }

    void topDown(int i) {
        int l = getLeft(i);
        int r = getRight(i);
        int largest = i;

        if (l != -1 && kopiec[l] > kopiec[largest]) {
            largest = l;
        }

        if (r != -1 && kopiec[r] > kopiec[largest]) {
            largest = r;
        }

        if (largest != i) {
            Element temp = kopiec[i];
            kopiec[i] = kopiec[largest];
            kopiec[largest] = temp;
            topDown(largest);
        }
    }
    
    // Wstawia element x do kolejki
    void insert(Element x) {
        if (full()) {
            cout << "Kolejka jest pelna!!!" << endl;
            return;
        }
        kopiec[size] = x;
        bottomUp(size);
        size++;
    }
    
    // Zwraca element z najwyzszym priorytetem (korzen)
    Element maxPriority() {
        if (empty()) {
            cout << "Kolejka jest pusta!!!" << endl;
            return Element(0,0); // Zwrocenie pustego elementu
        }
        return kopiec[0];
    }

    // Usuwa element z najwyzszym priorytetem
    void deleteMaxPriority() {
        if (empty()) {
            cout << "Kolejka jest pusta!!!" << endl;
            return;
        }
        
        size--;
        if (size > 0) {
            kopiec[0] = kopiec[size];
            topDown(0);
        }
    }
    
    // Usuwa element z pozycji i
    void del(int i) {
        if (i < 0 || i >= size) {
            cout << "Nieprawidlowy indeks!!!" << endl;
            return;
        }
        size--;
        
        // Jeśli to ostatni element
        if (i == size) return;
        
        Element removed = kopiec[i];
        Element replacement = kopiec[size];
        
        kopiec[i] = replacement;
        
        int p = getParent(i);
        
        if (p != -1 && kopiec[i] > kopiec[p]) {
            bottomUp(i);
        } else {
            topDown(i);
        }
    }
    
    friend ostream& operator<<(ostream& out, Heap& h);
};

ostream& operator<<(std::ostream& out, Heap& h) {
    out << endl;
    for (int i = 0; i < h.size; i++) {
        out << "[" << i << "] " << h.kopiec[i] << endl;
    }
    return out;
}

int main() {
    Heap h;
    cout << "ZWRACANIE ELEMENTOW" << endl;
    cout << "Stan poczatkowy: " << h << endl;
    cout << "Rozmiar kopca: " << h.getSize() << endl;
    cout << "Wartosc elementu 2: " << h.getValue(2) << endl;
    cout << "Priorytet elementu 2: " << h.getPriority(2) << endl;
    cout << "Lewy syn elementu 2: " << h.getLeft(2) << endl;
    cout << "Ojciec elementu 2: " << h.getParent(2) << endl;

    cout << endl << "TOP-DOWN"<< endl;
    cout << "Zmiana korzenia (15 -> 1)\n";
    h.setValue(0, Element(1, 'a'));
    cout << h << endl;

    cout << "topDown(0)\n";
    h.topDown(0);
    cout << "WYNIK:\n" << h << endl;
    cout << "Weryfikacja: Korzen powinien byc 12." << endl;

    cout << endl << "BOTTOM-UP" << endl;
    cout << "Zmiana elementu na dnie (indeks 11, wartosc -> 20)"<< endl;
    h.setValue(11, Element(20, 'S'));
    cout << h << endl;

    cout << "bottomUp(11)" << endl;
    h.bottomUp(11);
    cout << "WYNIK:\n" << h << endl;;
    cout << "Weryfikacja: Element [20: S] powinien byc w korzeniu (0)."<< endl;


    int c = 15;
    Heap ph(c);

    cout << endl << "INSERT" << endl;
    cout << "Wstawianie (8, 'c')..."; 
    ph.insert(Element(8, 'c')); 
    
    cout << "Stan: " << ph << endl;
    cout << "Wstawianie (12, 'a')..."; 
    ph.insert(Element(12, 'a'));
    cout << "Stan: " << ph << endl;

    cout << "Wstawianie (4, 'z')..."; 
    ph.insert(Element(4, 'z')); 
    cout << " Stan: " << ph << endl;
    
    cout << "Wstawianie (10, 'b')..."; 
    ph.insert(Element(10, 'b'));
    cout << " Stan: " << ph << endl;

    cout << endl << "MAX PRIORITY" << endl;
    Element max = ph.maxPriority();
    cout << "Element o najwyzszym priorytecie: " << max << endl;
    if (max.getP() == 12) cout << "-> OK" << endl; else cout << "-> BLAD" << endl;

    cout << endl << "DELETE MAX PRIORITY" << endl;
    cout << "Usuwanie max (oczekiwane usuniecie 12)..." << endl;
    ph.deleteMaxPriority();
    cout << "Stan po usunieciu: " << ph << endl;
    
    cout << "Nowy max: " << ph.maxPriority() << endl; // Powinno być 10
    if (ph.maxPriority().getP() == 10) cout << "-> OK" << endl; else cout << "-> BLAD" << endl;

    cout << endl << "DEL(i)" << endl;
    // Aktualny stan powinien byc mniej wiecej: [10] [8] [4]
    ph.insert(Element(2, 'x'));
    ph.insert(Element(1, 'y'));
    cout << "Stan przed del(1): " << ph << endl;
    
    // Usuwamy element z indeksu 1 (lewe dziecko korzenia, prawdopodobnie wartość 8)
    cout << "Usuwanie element z indeksu 1..." << endl;
    ph.del(1);
    cout << "Stan po del(1): " << ph << endl;

    cout << endl << "CZYSZCZENIE" << endl;
    while(!ph.empty()) {
        cout << "Usuwanie max: " << ph.maxPriority() << " -> ";
        ph.deleteMaxPriority();
        cout << ph << endl;
    }
    return 0;
}