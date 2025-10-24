/******************************************************************************

Lista: lista wiązana

Zadanie 1:

Dla dwukierunkowej listy wiązanej (reprezentacja oparta na wskaźnikach) 
proszę zaimplementować wskazane w szablonie operacje. 
Proszę przetestować poprawność ich działania – testy powinny być 
opracowane w taki sposób, aby weryfikowały działanie operacji we wszystkich 
możliwych do zaistnienia przypadkach. Testy powinny być zaprezentowane 
w sposób czytelny i jednoznaczny.

Szablon rozwiązania:

//Zadanie 1
class Element{
    private:
        int v;
        Element* next;
        Element* prev;
    
    public:
        Element(int x, Element* next, Element* prev);    //tworzy element przechowujący x
        int getValue();                                    //zwraca wartość
        void setValue(int v);                            //ustawia warość v
        Element* getNext();                                //zwraca ozycję następnego elementu
        Element* getPrev();                                //zwraca pozycję poprzedniego elementu
        void setNext(Element* p);                        //ustawia p jako następny element
        void setPrev(Element* p);                        //ustawia p jako poprzedni element
};


class LinkedList{
    private:
        Element* head;                    //pozycja pierwszego elementu
        Element* tail;                    //pozycja ostatniego elementu
        int size;
    
    public:
        LinkedList();                                //tworzy pustą listę
        bool empty();                                //zwraca prawdę jeśli lista pusta, fałsz w przeciwnym przypadku
        int getSize();                                //zwraca wielkość listy (liczbę elementów w liście)
      //  Element* getFirst();                         //zwraca pozycję (wskaźnik do) pierwszego elementu listy
      //  Element* getLast();                               //zwraca pozycję (wskaźnik do) ostatniego elementu listy
      //  Element* getNext(Element *p);               //zwraca pozycję (wskaźnik do) następnego elementu listy
      //  Element* getPrev(Element *p);              //zwraca pozycję (wskaźnik do) poprzedniego elementu listy
      //  int retrive(Element* p);                   //zwraca element (wartość) z pozycji (wskazywanej przez) p
         void append(int x);                            //wstawia element z x na końcu listy
        void preppend(int x);                            //wstawia element z x na początku listy
        friend ostream& operator<<(ostream& out, LinkedList* l); //wypisuje elementu listy               
        Element* locate(int x);          //zwraca pozycję (wskaźnik do) pierwszego wystąpienia elementu z x, NULL jeśli x nie występuje   
        void insert(Element* p, int x);              //wstawia element z wartością x na pozycję (wskazywaną przez) p, jeśli p = NULL to wstawia na koniec listy           
        void del(Element* p);                            //usuwa element z pozycji (wskazywanej przez) p       
        void clear();                    //usuwa wszystkie elementy z listy
        void deleteX(int x);              //usuwa pierwsze wystąpienie elementu o wartości x
        void deleteAllX(int x);            //usuwa wszystkie wystąpienia elementu o wartości x
        ~LinkedList();
};

//Zadanie 1 - przykładowy sposób testowania
LinkedList* a = new LinkedList();
cout<<endl<<"empty(): 1 - "<<a->empty();
cout<<endl<<"getSize():  0 - "<<a->getSize();
cout<<endl<<"append(4): 4 - "; a->append(4); cout<<" "<<a;     
//...

Zadanie 2:

Proszę utworzyć klasę SortedLinkedList. Dla klasy SortedLinkedList 
proszę zaimplementować operację umożliwiającą dodanie elementu x z 
zachowaniem porządku niemalejącego. Proszę przetestować poprawności 
działania w/w operacji w możliwych do zaistnienia przypadkach. Testy 
powinny być zaprezentowane w sposób czytelny i jednoznaczny.

Szablon rozwiązania:

//Zadanie 2
class SortedLinkedList{
    private:
        Element* head;                    //pozycja pierwszego elementu
        Element* tail;                    //pozycja ostatniego elementu
        int size;
    
    public:
        //konstruktor, destruktor, inne niezbędne operacje
        void insertSorted(int x);
};


Zadanie 3:

Do klas LinkedList i SortedLinkedList proszę dodać wskazane w szablonie 
operacje oraz zaimplementować je i przetestować poprawności ich działania
w możliwych do zaistnienia przypadkach. Testy powinny być zaprezentowane w 
sposób czytelny i jednoznaczny.

Szablon rozwiązania:

klasa LinkedList:
         bool concat(LinkedList *l);  //do bieżącej listy dołącza zawartość listy l

klasa SortedLinkedList:
          bool concat(SortedLinkedList *l);  //na do bieżącej listy dołącza zawartość listy l

*******************************************************************************/
#include <iostream>

using namespace std;

// --- KLASA ELEMENT ---
class Element {
    private:
        int v;
        Element* next;
        Element* prev;
    
    public:
        Element(int x, Element* nextPtr, Element* prevPtr) {
            v = x;
            next = nextPtr;
            prev = prevPtr;
        }

        int getValue() { return v; }
        void setValue(int val) { v = val; }
        
        Element* getNext() { return next; }
        Element* getPrev() { return prev; }
        
        void setNext(Element* p) { next = p; }
        void setPrev(Element* p) { prev = p; }
};

class LinkedList {
    private:
        Element* head;
        Element* tail;
        int size;
    
    public:
        LinkedList() {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        ~LinkedList() {
            clear();
        }

        bool empty() {
            return size == 0;
        }

        int getSize() {
            return size;
        }

        Element* getFirst() {
            return head;
        }

        Element* getLast() {
            return tail;
        }

        Element* getNext(Element* p) {
            if (p == NULL) return NULL;
            return p->getNext();
        }

        Element* getPrev(Element* p) {
            if (p == NULL) return NULL;
            return p->getPrev();
        }

        int retrieve(Element* p) {
            if (p == NULL) return -1;
            return p->getValue();
        }

        void append(int x) {
            Element* p = new Element(x, NULL, tail);
            if (empty()) {
                head = p;
                tail = p;
            } else {
                tail->setNext(p);
                tail = p;
            }
            size++;
        }

        void preppend(int x) {
            Element* p = new Element(x, head, NULL);
            if (empty()) {
                head = p;
                tail = p;
            } else {
                head->setPrev(p);
                head = p;
            }
            size++;
        }

        Element* locate(int x) {
            Element* current = head;
            while (current != NULL) {
                if (current->getValue() == x) {
                    return current;
                }
                current = current->getNext();
            }
            return NULL;
        }

        void insert(Element* p, int x) {
            if (p == NULL) {
                append(x);
                return;
            }
            if (p == head) {
                preppend(x);
                return;
            }
            Element* prevNode = p->getPrev();
            Element* newNode = new Element(x, p, prevNode);
            prevNode->setNext(newNode);
            p->setPrev(newNode);
            size++;
        }

        void del(Element* p) {
            if (p == NULL) return;
            if (p == head) {
                head = p->getNext();
                if (head != NULL) head->setPrev(NULL);
            } else {
                p->getPrev()->setNext(p->getNext());
            }
            if (p == tail) {
                tail = p->getPrev();
                if (tail != NULL) tail->setNext(NULL);
            } else {
                p->getNext()->setPrev(p->getPrev());
            }
            delete p;
            size--;
        }

        void deleteX(int x) {
            Element* p = locate(x);
            if (p != NULL) del(p);
        }

        void deleteAllX(int x) {
            Element* current = head;
            while (current != NULL) {
                Element* nextNode = current->getNext();
                if (current->getValue() == x) {
                    del(current);
                }
                current = nextNode;
            }
        }

        void clear() {
            while (head != NULL) {
                del(head);
            }
        }

        friend ostream& operator<<(ostream& out, LinkedList* l) {
            out << "[ ";
            Element* curr = l->head;
            while (curr != NULL) {
                out << curr->getValue() << " ";
                curr = curr->getNext();
            }
            out << "]";
            
            return out;
        }
};

int main() {
    cout << "=== ZADANIE 1 - TESTY ===" << endl;

    LinkedList* a = new LinkedList();

    // 1. Budowanie listy
    a->append(10);
    a->append(20);
    a->append(30);
    cout << "Lista: " << a << endl;

    // 2. Test metod nawigacyjnych (getFirst, getLast, getNext, getPrev, retrieve)
    cout << endl << "2. Test nawigacji:" << endl;
    
    Element* pierwszy = a->getFirst();
    Element* ostatni = a->getLast();

    cout << "   getFirst() -> wartosc: " << a->retrieve(pierwszy) << " (oczekiwane 10)" << endl;
    cout << "   getLast()  -> wartosc: " << a->retrieve(ostatni) << " (oczekiwane 30)" << endl;

    // Przejście "ręczne" po liście używając getNext
    cout << "   Reczne przejscie next:" << endl;
    Element* temp = a->getFirst();
    while(temp != NULL) {
        cout << "   -> " << a->retrieve(temp) << endl;
        temp = a->getNext(temp);
    }

    // Przejście wsteczne używając getPrev
    cout << "   Reczne przejscie prev (od konca):" << endl;
    temp = a->getLast();
    while(temp != NULL) {
        cout << "   -> " << a->retrieve(temp) << endl;
        temp = a->getPrev(temp);
    }

    // 3. Test retrieve z błędnym wskaźnikiem
    cout << endl << "3. Test retrieve(NULL): " << a->retrieve(NULL) << endl;

    // 4. Standardowe operacje (insert, del)
    cout << endl << "4. Insert i Del:" << endl;
    // Wstawiamy 15 przed 20 (20 jest następnikiem pierwszego elementu)
    Element* el20 = a->getNext(a->getFirst());
    a->insert(el20, 15);
    cout << "   Po insert(15): " << a << endl;

    a->del(el20); // Usuwamy element 20 (mamy do niego wskaźnik)
    cout << "   Po del(20):    " << a << endl;

    // Czyszczenie
    delete a;
    return 0;
}