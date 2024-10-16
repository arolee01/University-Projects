#include <iostream>

using namespace std;
int main(){
    cout<<"1. Rozmiar typu char to: "<< sizeof(char) << " bajt"<<endl;
    cout<<"2. Rozmiar typu short to: "<< sizeof(short)<< " bajty"<<endl;
    cout<<"3. Rozmiar typu int to: "<< sizeof(int)<< " bajty"<<endl;
    cout<<"4. Rozmiar typu long to: "<< sizeof(long)<< " bajtów"<<endl;
    cout<<"5. Rozmiar typu long long to: "<< sizeof(long long)<< " bajtów"<<endl;
    cout<<"6. Rozmiar typu float to: "<< sizeof(float)<< " bajty"<<endl;
    cout<<"7. Rozmiar typu double to: "<< sizeof(double)<< " bajtów"<<endl;
    cout<<"8. Rozmiar typu void to: "<< sizeof(void)<< " bajt"<<endl;
    cout<<"9. Rozmiar typu long double to: "<< sizeof(long double)<< " bajtów"<<endl;
    cout<<"10. Rozmiar typu bool to: "<<sizeof(bool)<< " bajt"<<endl;
    return 0;
}