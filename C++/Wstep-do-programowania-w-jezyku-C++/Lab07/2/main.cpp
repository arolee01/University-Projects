/******************************************************************************

Make changes to the code:

Decrease number of constructors using default parameters values. OK
Use initialization list. OK
Change print function so that it can be used also for t4 object. OK
What is the size of objects of class Time? Can they be made smaller? OK

*******************************************************************************/
#include <iostream>
using namespace std;
class Time{
	short hour;      // 0-23    wcześniej był użyty int, który ma 4 bajty (3*4 bajty = 12 bajtów)
	short minute;    // 0-59    zastąpiony shortem, który ma 2 bajty    (3*2 bajty = 6 bajtów)
	short second;    // 0-59
	                 //         ewentualnie można zastosować tylko zmienną 'short second' w klasie i później w metodach
	                 //         zamienić ją na minuty i sekundy, zmniejszając przy tym ilość zużytej pamięci do 2 bajtów
public:
    // konstruktory zostały zastąpione listą inicjalizacyjną
    Time(short h = 0, short m = 0, short s = 0) : hour(h), minute(m), second(s) {}

	void print() const{     // po print() został dopisany const, przrez co t4 może być wyświetlone
		cout << hour << ":"<< minute << ":" << second << endl; 
	}
};
int main(){	
	Time t1;
	Time t2(10);
	Time t3(10, 12);
	const Time t4(10, 12, 45);
	t1.print();
	t2.print();
	t3.print();
	t4.print();
	return 0;
}