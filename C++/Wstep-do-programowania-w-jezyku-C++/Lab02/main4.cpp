#include <iostream>

using namespace std;
int main()
{
    
    int x=1; 
    int y=5; 
    
    cout<<"Wartość x przed zmianą: "<<x<<endl;
    cout<<"Wartość y przed zmianą: "<<y<<endl;
    
    x=x+y; //1+5=6
    y=x-y; //6-5=1
    x=x-y; //6-1=5
    
    cout<<"Nowa wartość x: "<<x<<endl;
    cout<<"Nowa wartość y: "<<y<<endl;

    return 0;
}