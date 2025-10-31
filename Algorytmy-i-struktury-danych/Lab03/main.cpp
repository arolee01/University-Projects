/******************************************************************************

Stos, kolejka fifo

Zadanie 1:

Dla stosu reprezentowanego w oparciu o tablicę proszę zaimplementować wskazane
w szablonie operacje. Proszę przetestować poprawność ich działania – testy 
powinny być opracowane w taki sposób, aby weryfikowały działanie operacji we 
wszystkich możliwych do zaistnienia przypadkach. Testy powinny być
zaprezentowane w sposób czytelny i jednoznaczny.

Szablon rozwiązania:

//Zadanie 1

class ArrayStack{
    private:
        int* items;
        int capacity;        //pojemność stosu
        int top;                //wierzchołek stosu
    public:
        ArrayStack(int c);    //tworzy pusty stos o pojemności c
        bool empty();
        bool full();
        void push(int x);   //wstawia daną na stos
        int peek();            //zwraca daną ze stosu
        void pop();            //usuwa daną ze stosu
        void clear();       //usuwa wszystkie elementy ze stosu
        friend std::ostream& operator<<(std::ostream& out, ArrayStack& s);    //wyświetla całą zawartość stosu
        ~ArrayStack();
};

//Zadanie 1 - przykładowy sposób testowania
ArrayStack s(6);
cout<<endl<<"empty(): 1 - "<<s.empty();
cout<<endl<<"push(4): 4- "; s.push(4); cout<<" "<<s;
//...


Zadanie 2:

Dla stosu opartego na koncepcji jednokierunkowej listy wiązanej 
(reprezentacja oparta na wskaźnikach) proszę zaimplementować wskazane 
w szablonie operacje. Proszę przetestować poprawność ich działania według 
schematu dla zadania 1.

Szablon rozwiązania:

//Zadanie 2
class Element{
    private:
        int v;
        Element* next;
    public:
        Element(int x, Element* next);
        int getValue();
        Element* getNext();
        void setNext(Element* p);
};

class LinkedStack{
    private:
        Element* top;
    public:
        LinkedStack();        //tworzy pusty stos
        bool empty();
        void push(int x);  //wstawia daną na stos
        int peek();            //zwraca daną ze stosu
        void pop();            //usuwa element ze stosu
        void clear();       //usuwa wszystkie elementy ze stosu
        friend std::ostream& operator<<(std::ostream& out, LinkedStack* s); //wyświetla zawartość całego stosu
        ~LinkedStack();
};

//Zadanie 2 - przykładowy sposób testowania
LinkedStack* s = new LinkedStack();
cout<<endl<<"empty(): 1 - "<<s->empty();
cout<<endl<<"push(4): 4- "; s->push(4); cout<<" "<<s;
//...

Zadanie 3:

Dla kolejki fifo reprezentowanej w oparciu o tablicę proszę zaimplementować
wskazane w szablonie operacje. Proszę przetestować poprawność ich działania
– testy powinny być opracowane w taki sposób, aby weryfikowały działanie 
operacji we wszystkich możliwych do zaistnienia przypadkach. Testy powinny 
być zaprezentowane w sposób czytelny i jednoznaczny.

Szablon rozwiązania:

//Zadanie 3
class ArrayFifo{
    private:
        int* items;
        int capacity;            //pojemność kolejki
        int size;                //rozmiar kolejki (liczba elementów w kolejce)
        int head;                //indeks pierwszego elementu kolejki
        int tail;                  //indeks ostatniego elementu kolejki
    public:
        ArrayFifo(int c);        //tworzy pustą kolejkę o pojemności c
        bool empty();
        bool full();
        void enqueue(int x);  //dodaje daną do kolejki
        int peek();                   //zwraca daną z kolejki
        void dequeue();        //usuwa daną z kolejki
        void clear();               //usuwa wszystkie elementy z kolejki
        friend std::ostream& operator<<(std::ostream& out, ArrayFifo& f);    //wyświetla zawartość kolejki (od head do tail)
        ~ArrayFifo();
};

Zadanie 4:

Dla kolejki fifo na koncepcji jednokierunkowej listy wiązanej (reprezentacja 
oparta na wskaźnikach) proszę zaimplementować wskazane w szablonie operacje. 
Proszę przetestować poprawność ich działania według schematu dla zadania 3.

Szablon rozwiązania:

//do wykorzystania klasa Element z zadania 2

//Zadanie 4
class LinkedFifo{
    private:
        Element* head;
        Element* tail;
    public:
        LinkedFifo();     //tworzy pustą kolejkę
        bool empty();
        void enqueue(int x);   //dodaje daną do kolejki
        int peek();                //zwraca daną z kolejki
        void dequeue();            //usuwa daną z kolejki
        void clear();               //usuwa wszystkie elementy z kolejki 
        friend std::ostream& operator<<(std::ostream& out, LinkedFifo* f);    //wyświetla zawartość kolejki (od head do tail)
        ~LinkedFifo();
};

*******************************************************************************/
#include <iostream>

using namespace std;

class ArrayStack{
    private:
        int* items;
        int capacity;
        int top;
    public:
        ArrayStack(int c);
        bool empty();
        bool full();
        void push(int x);
        int peek();
        void pop();
        void clear();
        friend std::ostream& operator<<(std::ostream& out, ArrayStack& s);
        ~ArrayStack();
};

ArrayStack::ArrayStack(int c) {
    capacity = c;
    items = new int[capacity];
    top = -1;
}

ArrayStack::~ArrayStack() { delete[] items; }

bool ArrayStack::empty() { return top == -1; }

bool ArrayStack::full() { return top == capacity - 1; }

void ArrayStack::push(int x) {
    if (full()) {
        cout << " [Blad: Stos pelny. Nie mozna dodac " << x << "] ";
        return;
    }
    items[++top] = x;
}

int ArrayStack::peek() {
    if(empty()) {
        cout << " [Blad: Stos pusty] ";
        return -1;
    }
    return items[top];
}

void ArrayStack::pop() {
    if (empty()) {
        cout << " [Blad: Stos pusty. Nie mozna usunac] ";
        return;
    }
    top--;
}

void ArrayStack::clear() { top = -1; }

ostream& operator<<(ostream& out, ArrayStack& s) {
    out << "[ ";
    for (int i = 0; i <= s.top; i++) {
        out << s.items[i] << " ";
    }
    out << "]";
    return out;
}


class Element{
    private:
        int v;
        Element* next;
    public:
        Element(int x, Element* next);
        int getValue();
        Element* getNext();
        void setNext(Element* p);
};

Element::Element(int x, Element* nextPtr) {
    this->v = x;
    this->next = nextPtr;
}

int Element::getValue() { return v; }

Element* Element::getNext() { return next; }

void Element::setNext(Element* p) { next = p; }

class LinkedStack{
    private:
        Element* top;
    public:
        LinkedStack();
        bool empty();
        void push(int x);
        int peek();
        void pop();
        void clear();
        friend std::ostream& operator<<(std::ostream& out, LinkedStack* s);
        ~LinkedStack();
};

LinkedStack::LinkedStack() { top = nullptr; }

LinkedStack::~LinkedStack() { clear(); }

bool LinkedStack::empty() { return top == nullptr; }

void LinkedStack::push(int x) { top = new Element(x, top); }

int LinkedStack::peek() {
    if (empty()) {
        cout << " [Blad: Stos pusty!] ";
        return -1;
    }
    return top->getValue();
}

void LinkedStack::pop() {
    if (empty()) {
        cout << " [Blad: Stos pusty! Nie mozna usunac] ";
        return;
    }
    
    Element* temp = top;
    top = top->getNext();
    delete temp;
}

void LinkedStack::clear() {
    while (!empty()) {
        pop();
    }
}

ostream& operator<<(ostream& out, LinkedStack* s) {
    out << "[";
    Element* current = s->top;
    while (current != nullptr) {
        out << current->getValue() << " ";
        current = current->getNext();
    }
    out << "]";
    return out;
}

// Zadanie 3
class ArrayFifo{
    private:
        int* items;
        int capacity;
        int size;
        int head;
        int tail;
    public:
        ArrayFifo(int c);
        bool empty();
        bool full();
        void enqueue(int x);
        int peek();
        void dequeue();
        void clear();
        friend std::ostream& operator<<(std::ostream& out, ArrayFifo& f);
        ~ArrayFifo();
};

ArrayFifo::ArrayFifo(int c) {
    capacity = c;
    items = new int[capacity];
    clear();
}

ArrayFifo::~ArrayFifo() { delete[] items; }

bool ArrayFifo::empty() { return size == 0; }

bool ArrayFifo::full() { return size == capacity; }

void ArrayFifo::enqueue(int x) {
    if (full()) {
        cout << "Kolejka pelna. Nie mozna dodac (ArrayFifo enqueue()" << endl;
        return;
    }
    items[tail] = x; 
    tail = (tail + 1) % capacity;
    size++;
}

int ArrayFifo::peek() {
    if (empty()) {
        cout << "Kolejka pusta. Nie ma elementow do wyswietlenia (ArrayFifo peek()" << endl;
        return -1;
    }
    return items[head];
}

void ArrayFifo::dequeue() {
    if (empty()) {
        cout << "Kolejka pusta (ArrayFifo dequeue()" << endl;
        return;
    }
    head = (head + 1) % capacity;
    size--;
}

void ArrayFifo::clear() {
    head = 0;
    tail = 0;
    size = 0;
}

ostream& operator<<(ostream& out, ArrayFifo& f) {
    out << "[ ";
    int current = f.head;
    for (int i = 0; i<f.size; i++) {
        out << f.items[current] << " ";
        current = (current + 1) % f.capacity;
    }
    out << "]"; 
    return out;
}

class LinkedFifo{
    private:
        Element* head;
        Element* tail;
    public:
        LinkedFifo();
        bool empty();
        void enqueue(int x);
        int peek();
        void dequeue();
        void clear();
        friend std::ostream& operator<<(std::ostream& out, LinkedFifo* f); 
        LinkedFifo();
};

LinkedFifo::LinkedFifo() {
    head = nullptr;
    tail = nullptr;
}

LinkedFifo::~LinkedFifo() { clear(); }

bool LinkedFifo::empty() { return head ==  nullptr; }

void LinkedFifo::enqueue(int x) {
    Element* p = new Element(x, nullptr);
    
    if(empty()) {
        // Jeśli kolejka jest pusta, nowy element jest head i tail
        head = p;
        tail = p;
    } else {
        // Jeśli nie, podpinamy go za obecnym ogonem
        tail->setNext(p);
        tail = p;
    }
}

int LinkedFifo::peek() {
    if (empty()) {
        cout << "Kolejka pusta";
        return -1;
    }
    return head->getValue();
}

void LinkedFifo::dequeue() {
    if (empty()) {
        cout << "Kolejka pusta";
        return;
    }
    
    Element* temp = head;   // Zapamiętujemy głowe do przesuniecia
    head = head->getNext(); // Przesuwamy głowe na następny element
    
    if (head == nullptr) {
        // Jeśli po usunieciu kolejka jest pusta
        // to tail też musi być null
        tail = nullptr;
    }
    delete temp;
}

void LinkedFifo::clear() {
    while (!empty()) {
        dequeue();
    }
}

ostream& operator<<(ostream& out, LinkedFifo* f) {
    Element* current = f->head;
    out << "[ ";
    while (current != nullptr) {
        out << current->getValue() << " ";
        current = current->getNext();
    }
    out << "]";
    return out;
}

int main() {
    
    // --------------------------------------
    // TESTY ZADANIE 1 (ArrayStack)
    // --------------------------------------
    cout << "=== ZADANIE 1: TESTY STOSU TABLICOWEGO (ArrayStack) ===" << endl;

    // 1. Utworzenie stosu
    int size = 5;
    cout << "\n--- Test 1: Inicjalizacja (pojemnosc: " << size << ") ---" << endl;
    ArrayStack s(size);
    cout << "Stos: " << s << endl;
    cout << "empty(): " << s.empty() << " (Oczekiwane: 1)" << endl;

    // 2. Dodawanie elementów (Push)
    cout << "\n--- Test 2: Dodawanie elementow (Push) ---" << endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Po dodaniu 10, 20, 30: " << s << endl;
    cout << "empty(): " << s.empty() << " (Oczekiwane: 0)" << endl;

    // 3. Peek (Podgląd)
    cout << "\n--- Test 3: Peek (Podglad wierzcholka) ---" << endl;
    cout << "Wierzcholek: " << s.peek() << " (Oczekiwane: 30)" << endl;

    // 4. Wypełnienie stosu do pełna
    cout << "\n--- Test 4: Zapelnienie stosu ---" << endl;
    s.push(40);
    s.push(50);
    cout << "Dodano 40, 50. Stos: " << s << endl;
    cout << "full(): " << s.full() << " (Oczekiwane: 1)" << endl;

    // 5. Przepełnienie (Overflow)
    cout << "\n--- Test 5: Proba przepelnienia (Overflow) ---" << endl;
    cout << "Proba push(60): ";
    s.push(60); // Powinno wyświetlić błąd
    cout << endl;

    // 6. Usuwanie elementów (Pop)
    cout << "\n--- Test 6: Usuwanie (Pop) ---" << endl;
    s.pop();
    cout << "Po pop(): " << s << " (Usunieto 50)" << endl;
    cout << "Nowy wierzcholek: " << s.peek() << " (Oczekiwane: 40)" << endl;

    // 7. Czyszczenie (Clear)
    cout << "\n--- Test 7: Czyszczenie (Clear) ---" << endl;
    s.clear();
    cout << "Po clear(): " << s << endl;
    cout << "empty(): " << s.empty() << " (Oczekiwane: 1)" << endl;


    // --------------------------------------
    // TESTY ZADANIE 2 (LinkedStack)
    // --------------------------------------
    cout << "\n\n==================================================" << endl;
    cout << "=== ZADANIE 2: TESTY STOSU NA LISCIE (LinkedStack) ===" << endl;
    cout << "==================================================" << endl;

    // 1. Utworzenie stosu
    // Używamy zmiennej 'ls' zamiast 's', aby nie było konfliktu nazw
    LinkedStack* ls = new LinkedStack(); 
    
    cout << "\n--- Test 1: Inicjalizacja ---" << endl;
    cout << "Stos ls: " << ls << endl;
    cout << "empty(): " << ls->empty() << " (Oczekiwane: 1)" << endl;

    // 2. Dodawanie (Push)
    cout << "\n--- Test 2: Dodawanie elementow (Push) ---" << endl;
    ls->push(4);
    cout << "push(4): " << ls << endl;
    ls->push(10);
    ls->push(20);
    cout << "Po dodaniu 10, 20: " << ls << endl;
    cout << "empty(): " << ls->empty() << " (Oczekiwane: 0)" << endl;

    // 3. Peek
    cout << "\n--- Test 3: Peek (Podglad) ---" << endl;
    cout << "peek(): " << ls->peek() << " (Oczekiwane: 20)" << endl;

    // 4. Usuwanie (Pop)
    cout << "\n--- Test 4: Usuwanie (Pop) ---" << endl;
    ls->pop();
    cout << "Po pop(): " << ls << " (Usunieto 20)" << endl;
    cout << "Nowy wierzcholek: " << ls->peek() << " (Oczekiwane: 10)" << endl;

    // 5. Test Clear
    cout << "\n--- Test 5: Clear ---" << endl;
    ls->clear();
    cout << "Po clear(): " << ls << endl;
    cout << "empty(): " << ls->empty() << " (Oczekiwane: 1)" << endl;

    // 6. Test błędów na pustym
    cout << "\n--- Test 6: Operacje na pustym ---" << endl;
    cout << "Proba pop(): "; ls->pop(); cout << endl;
    cout << "Proba peek(): "; ls->peek(); cout << endl;

    // Sprzątanie pamięci
    delete ls;
    
    // --------------------------------------
    // TESTY ZADANIE 3 (ArrayFifo)
    // --------------------------------------
    cout << "\n\n==================================================" << endl;
    cout << "=== ZADANIE 3: TESTY KOLEJKI FIFO (ArrayFifo) ===" << endl;
    cout << "==================================================" << endl;

    // 1. Inicjalizacja
    int qSize = 4; // Mała pojemność, żeby łatwo przetestować przepełnienie
    cout << "\n--- Test 1: Inicjalizacja (pojemnosc: " << qSize << ") ---" << endl;
    ArrayFifo q(qSize);
    cout << "Kolejka: " << q << endl;
    cout << "empty(): " << q.empty() << " (Oczekiwane: 1)" << endl;

    // 2. Enqueue (Dodawanie)
    cout << "\n--- Test 2: Enqueue (10, 20, 30) ---" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Kolejka: " << q << endl;
    cout << "peek(): " << q.peek() << " (Oczekiwane: 10 - FIFO)" << endl;

    // 3. Dequeue (Usuwanie)
    cout << "\n--- Test 3: Dequeue (Usuniecie 1 elementu) ---" << endl;
    q.dequeue(); // usuwa 10
    cout << "Po dequeue(): " << q << " (Usunieto 10)" << endl;
    cout << "peek(): " << q.peek() << " (Oczekiwane: 20)" << endl;

    // 4. Test Cykliczności (Kluczowy!)
    /* Mamy pojemność 4. Aktualnie w kolejce są [20, 30] (zajęte 2 miejsca).
       Indices (fizyczne w tablicy): [_, 20, 30, _] (head=1, tail=3).
       Dodamy dwa elementy (40, 50). 50 powinno "zawinąć się" na początek tablicy (indeks 0).
    */
    cout << "\n--- Test 4: Cyklicznosc (Wypelnienie po usunieciu) ---" << endl;
    q.enqueue(40);
    q.enqueue(50);
    cout << "Dodano 40, 50. Kolejka powinna byc pelna." << endl;
    cout << "Kolejka: " << q << endl; // Powinno pokazać poprawną kolejność: 20 30 40 50
    cout << "full(): " << q.full() << " (Oczekiwane: 1)" << endl;

    // 5. Przepełnienie
    cout << "\n--- Test 5: Przepelnienie ---" << endl;
    cout << "Proba enqueue(60): ";
    q.enqueue(60); 
    cout << endl;

    // 6. Opróżnianie
    cout << "\n--- Test 6: Oproznianie calkowite ---" << endl;
    q.dequeue(); // usuwa 20
    q.dequeue(); // usuwa 30
    q.dequeue(); // usuwa 40
    q.dequeue(); // usuwa 50
    cout << "Po 4x dequeue: " << q << endl;
    cout << "empty(): " << q.empty() << " (Oczekiwane: 1)" << endl;

    // 7. Clear i błędy
    cout << "\n--- Test 7: Clear i bledy ---" << endl;
    q.enqueue(100);
    q.clear();
    cout << "Po clear(): " << q << endl;
    cout << "Proba dequeue na pustej: "; q.dequeue(); cout << endl;

    // --- ZADANIE 4 (NOWE TESTY) ---
    cout << "\n=== ZADANIE 4: LinkedFifo ===" << endl;
    
    // 1. Inicjalizacja
    LinkedFifo* lq = new LinkedFifo();
    cout << "--- Test 1: Pusta kolejka ---" << endl;
    cout << "empty(): " << lq->empty() << " (Oczekiwane: 1)" << endl;

    // 2. Enqueue (Dodawanie)
    cout << "\n--- Test 2: Enqueue (100, 200, 300) ---" << endl;
    lq->enqueue(100);
    lq->enqueue(200);
    lq->enqueue(300);
    cout << "Kolejka: " << lq << endl;
    cout << "empty(): " << lq->empty() << " (Oczekiwane: 0)" << endl;

    // 3. Peek
    cout << "\n--- Test 3: Peek ---" << endl;
    cout << "peek(): " << lq->peek() << " (Oczekiwane: 100)" << endl;

    // 4. Dequeue (Usuwanie)
    cout << "\n--- Test 4: Dequeue ---" << endl;
    lq->dequeue(); // usuwa 100
    cout << "Po usunieciu 100: " << lq << endl;
    cout << "Nowy peek(): " << lq->peek() << " (Oczekiwane: 200)" << endl;

    // 5. Opróżnianie całkowite (Sprawdzenie logiki tail=nullptr)
    cout << "\n--- Test 5: Oproznienie do zera ---" << endl;
    lq->dequeue(); // usuwa 200
    lq->dequeue(); // usuwa 300
    cout << "Po usunieciu wszystkiego: " << lq << endl;
    cout << "empty(): " << lq->empty() << " (Oczekiwane: 1)" << endl;

    // 6. Ponowne dodanie po opróżnieniu (Sprawdzenie czy tail działa)
    cout << "\n--- Test 6: Ponowne dodanie (500) ---" << endl;
    lq->enqueue(500);
    cout << "Kolejka: " << lq << endl;

    // 7. Clear
    cout << "\n--- Test 7: Clear ---" << endl;
    lq->enqueue(600);
    lq->clear();
    cout << "Po clear(): " << lq << endl;

    delete lq;
    
    return 0;
}