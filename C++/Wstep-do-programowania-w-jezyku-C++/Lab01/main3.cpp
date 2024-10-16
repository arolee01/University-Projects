#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "1. "<<endl;
    cout << "Maksimum dla typu int to: " <<numeric_limits<int>::max()<<endl;
    cout << "Minimum dla typu int : " <<numeric_limits<int>::min()<<endl;

    cout << "2. "<<endl;
    cout << "Maksimum dla typu double to: " <<numeric_limits<double>::max()<<endl;
    cout << "Minimum dla typu double : " <<numeric_limits<double>::min()<<endl;
    
    cout << "3. "<<endl;
    cout << "Maksimum dla typu short to: " <<numeric_limits<short>::max()<<endl;
    cout << "Minimum dla typu short : " <<numeric_limits<short>::min()<<endl;
    
    cout << "4. "<<endl;
    cout << "Maksimum dla typu long to: " <<numeric_limits<long>::max()<<endl;
    cout << "Minimum dla typu long : " <<numeric_limits<long>::min()<<endl;
    
    cout << "5. "<<endl;
    cout << "Maksimum dla typu long long to: " <<numeric_limits<long long>::max()<<endl;
    cout << "Minimum dla typu long long : " <<numeric_limits<long long>::min()<<endl;
    
    cout << "6. "<<endl;
    cout << "Maksimum dla typu float to: " <<numeric_limits<float>::max()<<endl;
    cout << "Minimum dla typu float : " <<numeric_limits<float>::min()<<endl;
    
    cout << "7. "<<endl;
    cout << "Maksimum dla typu long double to: " <<numeric_limits<long double>::max()<<endl;
    cout << "Minimum dla typu long double : " <<numeric_limits<long double>::min()<<endl;
    
    cout << "8. "<<endl;
    cout << "Maksimum dla typu unsigned long to: " <<numeric_limits<unsigned long>::max()<<endl;
    cout << "Minimum dla typu unsigned long : " <<numeric_limits<unsigned long>::min()<<endl;
    
    cout << "9. "<<endl;
    cout << "Maksimum dla typu unsigned int to: " <<numeric_limits<unsigned int>::max()<<endl;
    cout << "Minimum dla typu unsigned int : " <<numeric_limits<unsigned int>::min()<<endl;
    
    
    cout << "10. "<<endl;
    cout << "Maksimum dla typu unsigned short to: " <<numeric_limits<unsigned short>::max()<<endl;
    cout << "Minimum dla typu unsigned short : " <<numeric_limits<unsigned short>::min()<<endl;
    
    return 0;
}