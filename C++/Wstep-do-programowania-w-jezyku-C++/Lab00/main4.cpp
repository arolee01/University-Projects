#include <iostream>

using namespace std;

int main()
{
    
string napis1, napis2;
cout<<"Wprowadz pierwszy napis: "<<endl;
cin>>napis1;
cout<<"Wprowadz drugi napis: "<<endl;
cin>>napis2;
cout<<"Wprowadz trzeci napis: "<<endl;
cin>>napis3;

cout<<"Pierwszy napis: "+napis1<<endl;
cout<<"Drugi napis: "+napis2<<endl;
cout<<"Trzeci napis: "+napis3<<endl;

cout<<"1. "+napis1+" "+napis2+" "+napis3<<endl;
cout<<"2. "+napis1+" "+napis3+" "+napis2<<endl;
cout<<"3. "+napis2+" "+napis1+" "+napis3<<endl;
cout<<"4. "+napis2+" "+napis3+" "+napis1<<endl;
cout<<"5. "+napis3+" "+napis1+" "+napis2<<endl;
cout<<"6. "+napis3+" "+napis2+" "+napis1<<endl;


return 0;
}