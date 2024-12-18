#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
    Vector x(3);
    x.at(1) = 1;   x.at(2)=2;   x.at(3) = 3;
    Vector y(3);
    y.at(1) = 2;   y.at(2)=4;   y.at(3) = 6;

    cout << " x = " << x << " y = " << y<< endl;  // x = (1, 2, 3)  y=(2, 4, 6)

    cout << " x + y = " << x + y << endl;   // x + y = (3, 6, 9)
    cout << " x - y = " << x - y << endl;   // x - y = (-1, -2, -3)
    cout << " x * y = " << x * y << endl;   // x * y = 16
    cout << " (x+y) * (x-y) = " << (x+y) * (x-y) << endl;  //(x+y) * (x-y) = -42
    
    if(x==y) cout << "Equal vectors"; 
    if(x!=y) cout << " Not equal vectors";

    x[1] = 2;
    cout << " x= " << x << endl;    // x = (2, 2, 3)
    
    if(x < y) cout << "x < y " << endl;   // x<y
    if(x >=y) cout << "x >= y " << endl;
    
    x += y;
    cout << " x= " << x << endl;    // x = (4, 6, 9)
    x *= 2;
    cout << " x= " << x << endl;    // x = (8, 12, 18)
    
    return 0;
}
