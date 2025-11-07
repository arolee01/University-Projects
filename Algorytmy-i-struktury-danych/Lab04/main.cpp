/******************************************************************************

Drzewo binarne: BST

Zadanie 1:

Dla binarnego drzewa poszukiwań (BST) proszę zaimplementować wskazane w 
szablonie operacje. Proszę przetestować poprawność ich działania – testy 
powinny być opracowane w taki sposób, aby weryfikowały działanie operacji
we wszystkich możliwych do zaistnienia przypadkach. Testy powinny być 
zaprezentowane w sposób czytelny i jednoznaczny.

Metoda getRoot() jest metodą pomocniczą umożliwiającą dostęp do drzewa.

Szablon rozwiązania:

//Zadanie 1
class Node{
    private:
        int value;
        Node* left;
        Node* right;
        Node* parent;
    public:
        Node(int v, Node* l, Node* r, Node* p);
        int getValue();
        Node* getLeft();
        Node* getRight();
        Node* getParent();
        void setValue(int v);
        void setLeft(Node* l);
        void setRight(Node* r);
        void setParent(Node* p);
};

class BSTree{
    private:
        Node* root;
    public:
        BSTree();                        //tworzy puste drzewo 
        Node* getRoot();            //zwraca wskaźnik do root - metoda pomocnicza w testowaniu
        bool empty(Node* p);        //zwraca prawdę gdy (pod)drzewo o korzeniu p jest puste
        void inorder(Node* p);      //wyświetla w porządku inorder
    //BST   
        void insert(int x);            //wstawia węzeł z wartością x
        Node* search(int x);         //zwraca wskaźnik do węzła z wartością x (lub NULL jeśli nie istnieje)
        Node* minimum(Node* p);            //zwraca wskaźnik do węzła z minimalną wartością w (pod)drzewie p
        Node* maximum(Node* p);            //zwraca wskaźnik do węzła z maksymalną wartością w (pod)drzewie p
        Node* successor(Node* p);    //zwraca wskaźnik do następnika p
        Node* predecessor(Node* p);    //zwraca wskaźnik do poprzednika p
        void del(Node* p);            //usuwa węzeł wskazywany przez p
};

//Zadanie 1 - przykładowe testowanie
BSTree* t = new BSTree();
count<<" insert(3) : 3 "; t->insert(3); t->inorder(t->getRoot());
//...

Zadanie 2:

Do klasy z zadanie 1 proszę dodać wskazane w szablonie operacje 
oraz zaimplementować je i przetestować poprawności ich działania w
możliwych do zaistnienia przypadkach. Testy powinny być zaprezentowane
w sposób czytelny i jednoznaczny.


Szablon rozwiązania:

//Zadanie 2

int size(Node* p);                  //zwraca rozmiar (pod)drzewa o korzeniu p
int hight(Node* p);              //zwraca wysokość (pod)drzewa o korzeniu p
void clear(Node* p);           //usuwa wszystkie węzły z (pod)drzewa o korzeniu p

*******************************************************************************/
#include <iostream>
#include <algorithm>

using namespace std;

class Node {
    private:
        int value;
        Node* left;
        Node* right;
        Node* parent;
    public:
        Node(int v, Node* l, Node* r, Node* p);
        int getValue();
        Node* getLeft();
        Node* getRight();
        Node* getParent();
        void setValue(int v);
        void setLeft(Node* l);
        void setRight(Node* r);
        void setParent(Node* p);
};

Node::Node(int v, Node* l, Node* r, Node* p) {
    this->value = v;
    this->left = l;
    this->right = r;
    this->parent = p;
}

int Node::getValue() { return value; }
Node* Node::getLeft() { return left; }
Node* Node::getRight() { return right; }
Node* Node::getParent() { return parent; }
void Node::setValue(int v) { value = v; }
void Node::setLeft(Node* l) { left = l; }
void Node::setRight(Node* r) { right = r; }
void Node::setParent(Node* p) { parent = p; }


class BSTree {
    private:
        Node* root;
    public:
        BSTree();
        Node* getRoot();
        bool empty(Node* p);
        void inorder(Node* p); 
        
        void insert(int x);
        Node* search(int x);
        Node* minimum(Node* p);
        Node* maximum(Node* p);
        Node* successor(Node* p);
        Node* predecessor(Node* p);
        void del(Node* p);

        int size(Node* p);
        int hight(Node* p);
        void clear(Node* p);
        void clearRoot();
    
};

BSTree::BSTree() {
    root = nullptr;
}

Node* BSTree::getRoot() {
    return root;
}

bool BSTree::empty(Node* p) {
    return p == nullptr;
}

void BSTree::inorder(Node* p) {
    if (p != nullptr) {
        inorder(p->getLeft());
        cout << p->getValue() << " ";
        inorder(p->getRight());
    }
}

void BSTree::insert(int x) {
    Node* newNode = new Node(x, nullptr, nullptr, nullptr);
    
    Node* y = nullptr;
    Node* x_ptr = root;
    
    while (x_ptr != nullptr) {
        y = x_ptr;
        if (newNode->getValue() < x_ptr->getValue())
            x_ptr = x_ptr->getLeft();
        else
            x_ptr = x_ptr->getRight();
    }
    
    newNode->setParent(y);
    
    if (y == nullptr) {
        root = newNode;
    } else if (newNode->getValue() < y->getValue()) {
        y->setLeft(newNode);
    } else {
        y->setRight(newNode);
    }
}

Node* BSTree::search(int x) {
    Node* current = root;
    while (current != nullptr && x != current->getValue()) {
        if (x < current->getValue())
            current = current->getLeft();
        else
            current = current->getRight();
    }
    return current;
}

Node* BSTree::minimum(Node* p) {
    while (p->getLeft() != nullptr) {
        p = p->getLeft();
    }
    return p;
}

Node* BSTree::maximum(Node* p) {
    while (p->getRight() != nullptr) {
        p = p->getRight();
    }
    return p;
}

Node* BSTree::successor(Node* p) {
    // Jeśli ma prawe poddrzewo - idź w prawo, potem max w lewo
    if (p->getRight() != nullptr) {
        return minimum(p->getRight());
    }
    
    // Nie ma prawego poddrzewa - idź w górę
    Node* y = p->getParent();
    // Dopóki p jest prawym synem swojego rodzica, idź w górę
    while (y != nullptr && p == y->getRight()) {
        p = y;
        y = y->getParent();
    }
    return y;
}

Node* BSTree::predecessor(Node* p) {
    // Ma lewe poddrzewo - idź w lewo, potem max w prawo
    if (p->getLeft() != nullptr) {
        return maximum(p->getLeft());
    }
    
    // Nie ma lewego poddrzewa - idź w górę
    Node* y = p->getParent();
    // Dopóki p jest lewym synem swojego rodzica, idź w górę
    while (y != nullptr && p == y->getLeft()) {
        p = y;
        y = y->getParent();
    }
    return y;
}

void BSTree::del(Node* z) {
    if (z == nullptr) return;

    Node* y;
    Node* x;

    if (z->getLeft() == nullptr || z->getRight() == nullptr)
        y = z;
    else
        y = successor(z);


    if (y->getLeft() != nullptr)
        x = y->getLeft();
    else
        x = y->getRight();


    if (x != nullptr)
        x->setParent(y->getParent());

    if (y->getParent() == nullptr) {
        root = x;
    } else if (y == y->getParent()->getLeft()) {
        y->getParent()->setLeft(x);
    } else {
        y->getParent()->setRight(x);
    }

    if (y != z) {
        z->setValue(y->getValue());
    }

    delete y;
}

int BSTree::size(Node* p) {
    if (p == nullptr) return 0;
    return 1 + size(p->getLeft()) + size(p->getRight());
}

int BSTree::hight(Node* p) {
    if (p == nullptr) return -1;
    
    return max(hight(p->getLeft()), hight(p->getRight())) + 1;
}

void BSTree::clear(Node* p) {
    if (p == nullptr) return;

    clear(p->getLeft());
    clear(p->getRight());

    delete p;
}

void BSTree::clearRoot() {
    clear(root);
    root = nullptr;
}

int main() {
    cout << "=== TESTY DRZEWA BST ===" << endl;

    BSTree* t = new BSTree();

    // 1. Budowa drzewa
    /* Struktura drzewa do testów:
            15
           /  \
          6    18
         / \   / \
        3   7 17 20
         \   \
          4   13
             /
            9
    */
    cout << "\n--- Test 1: Insert (budowa drzewa) ---" << endl;
    t->insert(15);
    t->insert(6);
    t->insert(18);
    t->insert(3);
    t->insert(7);
    t->insert(17);
    t->insert(20);
    t->insert(4);
    t->insert(13);
    t->insert(9);

    cout << "Inorder: ";
    t->inorder(t->getRoot());
    cout << "\n(Oczekiwane: 3 4 6 7 9 13 15 17 18 20)" << endl;

    // 2. Search
    cout << "\n--- Test 2: Search ---" << endl;
    Node* s1 = t->search(13);
    cout << "Szukam 13: " << (s1 ? "Znaleziono" : "Nie znaleziono") << endl;
    Node* s2 = t->search(99);
    cout << "Szukam 99: " << (s2 ? "Znaleziono" : "Nie znaleziono") << endl;

    // 3. Min/Max
    cout << "\n--- Test 3: Min / Max ---" << endl;
    cout << "Min w calym drzewie: " << t->minimum(t->getRoot())->getValue() << " (Oczekiwane: 3)" << endl;
    cout << "Max w calym drzewie: " << t->maximum(t->getRoot())->getValue() << " (Oczekiwane: 20)" << endl;
    
    Node* subtree = t->search(6);
    cout << "Max w poddrzewie '6': " << t->maximum(subtree)->getValue() << " (Oczekiwane: 13)" << endl;

    // 4. Successor (Następnik)
    cout << "\n--- Test 4: Successor (Nastepnik) ---" << endl;
    // a) Następnik ma prawe dziecko
    Node* n1 = t->search(6);
    cout << "Successor(6): " << t->successor(n1)->getValue() << " (Oczekiwane: 7 - min w prawym poddrzewie)" << endl;
    
    // b) Następnik nie ma prawego dziecka (wyjście w górę)
    Node* n2 = t->search(13);
    cout << "Successor(13): " << t->successor(n2)->getValue() << " (Oczekiwane: 15 - rodzic w gore)" << endl;

    // 5. Predecessor (Poprzednik)
    cout << "\n--- Test 5: Predecessor (Poprzednik) ---" << endl;
    Node* p1 = t->search(6); // poprzednik to 4 (max lewego poddrzewa)
    cout << "Predecessor(6): " << t->predecessor(p1)->getValue() << " (Oczekiwane: 4)" << endl;
    
    Node* p2 = t->search(17); // brak lewego, idziemy w górę -> 15
    cout << "Predecessor(17): " << t->predecessor(p2)->getValue() << " (Oczekiwane: 15)" << endl;


    // 6. Usuwanie (Delete)
    cout << "\n--- Test 6: Delete (Usuwanie) ---" << endl;

    // Przypadek A: Liść (bez dzieci) -> usuwamy 17
    cout << "A) Usuwanie liscia (17): ";
    t->del(t->search(17));
    t->inorder(t->getRoot());
    cout << endl;

    // Przypadek B: Jedno dziecko -> usuwamy 7 (ma dziecko 13)
    cout << "B) Usuwanie wezla z 1 dzieckiem (7): ";
    t->del(t->search(7));
    t->inorder(t->getRoot());
    cout << "\n(7 zniknelo, 13 powinno wejsc na jego miejsce)" << endl;

    // Przypadek C: Dwoje dzieci -> usuwamy korzeń 15 (zastąpi go następnik 18)
    /* Uwaga: W tym stanie drzewa:
       Korzeń 15. Prawy syn 18. Lewy syn 18 to NULL.
       Więc następnikiem 15 jest 18.
    */
    cout << "C) Usuwanie wezla z 2 dzieci (15 - root): ";
    t->del(t->search(15));
    t->inorder(t->getRoot());
    cout << "\n(Root 15 usuniety, struktura zachowana)" << endl;

    delete t;
    
    
    // 1. Test na pustym drzewie
    cout << "\n--- Test 1: Puste drzewo ---" << endl;
    cout << "size(): " << t->size(t->getRoot()) << " (Oczekiwane: 0)" << endl;
    cout << "hight(): " << t->hight(t->getRoot()) << " (Oczekiwane: -1)" << endl;

    // 2. Budowa drzewa (jak w Zadaniu 1)
    /* 15  (h=3)
           /  \
          6    18 (h=2)
         / \   / \
        3   7 17 20
         \   \
          4   13
             /
            9  (h=0 - liść)
    */
    t->insert(15); t->insert(6); t->insert(18);
    t->insert(3); t->insert(7); t->insert(17);
    t->insert(20); t->insert(4); t->insert(13); t->insert(9);

    cout << "\n--- Test 2: Drzewo wypelnione (10 elementow) ---" << endl;
    t->inorder(t->getRoot()); cout << endl;
    
    // TEST SIZE
    int s = t->size(t->getRoot());
    cout << "size(root): " << s << " (Oczekiwane: 10)" << endl;

    // Test size dla poddrzewa (korzeń 6 ma pod sobą: 3, 4, 7, 13, 9 -> razem 6 węzłów)
    Node* sub = t->search(6);
    cout << "size(wezel 6): " << t->size(sub) << " (Oczekiwane: 6)" << endl;

    // TEST HIGHT
    cout << "\n--- Test 3: Hight (Wysokosc) ---" << endl;
    // Wysokość korzenia (15 -> 6 -> 7 -> 13 -> 9) = 4 krawędzie
    cout << "hight(root): " << t->hight(t->getRoot()) << " (Oczekiwane: 4)" << endl;
    
    // Wysokość liścia (np. 9) -> 0
    cout << "hight(wezel 9): " << t->hight(t->search(9)) << " (Oczekiwane: 0)" << endl;

    // Wysokość węzła 18 (ścieżka 18->20 lub 18->17) -> 1
    cout << "hight(wezel 18): " << t->hight(t->search(18)) << " (Oczekiwane: 1)" << endl;

    // TEST CLEAR
    cout << "\n--- Test 4: Clear (Czyszczenie) ---" << endl;
    
    // Sprawdzamy, czy clear() działa rekurencyjnie
    // Używam metody clearRoot(), która wywołuje clear(root) i ustawia root = nullptr
    t->clearRoot();
    
    cout << "Drzewo wyczyszczone." << endl;
    cout << "size(): " << t->size(t->getRoot()) << " (Oczekiwane: 0)" << endl;
    cout << "empty(): " << t->empty(t->getRoot()) << " (Oczekiwane: 1)" << endl;
    
    // Sprawdzenie ponownego użycia po wyczyszczeniu
    t->insert(100);
    cout << "Dodano 100 po wyczyszczeniu. size(): " << t->size(t->getRoot()) << endl;

    delete t;
    return 0;
}