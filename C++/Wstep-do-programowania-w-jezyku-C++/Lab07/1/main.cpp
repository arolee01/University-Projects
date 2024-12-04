/******************************************************************************

Zaimplementuj klasę Clock: OK
Klasa powinna mieć pola prywatne reprezentujące godzinę minutę i sekundę. OK
Konstruktor domyślny niech inicjuje godzinę 00:00:00. OK
Utwórz konstruktor 3-argumentowy, gdzie argumentami będą godzina, minuty(domyślnie 0) i sekundy(domyślnie 0). OK
Napisz metodę tick(), która będzie zwiększała wskazanie zegara o sekundę. OK
Napisz metody zwiększające godziny, minuty, sekundy o podane jako argument wartości. OK
Funkcja może przyjmować też wartości ujemne. OK
Dwa zegary są równe wtedy gdy reprezentują ten sam czas. 
Zaimplementuj metodę zwracającą napis reprezentujący przechowywaną godzinę. OK

*******************************************************************************/
#include <iostream>
#include "methods.h"

using namespace std;

int main()
{
    Clock nowyZegar(23,59,59);
    nowyZegar.actualTime();
    nowyZegar.tick();
    nowyZegar.actualTime();
    nowyZegar.addTime(26, -128,234); // 26 godzin - 2 godziny i 8 minut + 3 minuty i 54 sekundy
    nowyZegar.actualTime();          // 23 godziny 55 minut 54 sekundy
    
    Clock kolejnyZegar(23, 55, 54);
    Clock nastepnyZegar;
    cout << nowyZegar.isEqual(kolejnyZegar) << endl;
    cout << nowyZegar.isEqual(nastepnyZegar) << endl;
}