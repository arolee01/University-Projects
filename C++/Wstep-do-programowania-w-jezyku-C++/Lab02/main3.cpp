#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout<<"Podaj liczbę: "<<endl;
    cin>>n;

    cout<<"Trójki pitagorejskie dla liczb mniejszych od: "<<n<<endl;
    for (int a=1; a<n; a++) { //Wykonuje dla a mniejszych od n
        for (int b=a; b<n; b++) { //Wykonuje dla b=a, bo wtedy pokazuje pojedynczy wynik zamiast np. ((3, 4, 5), (4, 3, 5)) przy b=1
            int c = sqrt(a * a + b * b); // a^2+b^2=c^2, wylicza samo c z pierwiastka
            if (c<n && a * a + b * b == c * c) { // Jeśli c jest mniejsze od n i wynik a^2+b^2=c^2 jest prawdziwy to wypisuje trójkę pitagorejską
                cout <<"("<<a<<", "<<b<<", "<<c<<")\n";
            }
        }
    }
    return 0;
}