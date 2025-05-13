#ifndef MENU_H
#define MENU_H

 /*
  * Wyœwietla menu g³ówne i pobiera wybór u¿ytkownika
  * @return Wybrana opcja menu (1 dla LCG, 2 dla Addytywnej)
  */
int showMenu();

/*
 * Pobiera parametry dla Liniowej Metody Kongruencyjnej od u¿ytkownika
 * @param a Referencja do zmiennej przechowuj¹cej mno¿nik
 * @param c Referencja do zmiennej przechowuj¹cej przyrost
 * @param m Referencja do zmiennej przechowuj¹cej modu³
 * @param seed Referencja do zmiennej przechowuj¹cej ziarno
 * @param n Referencja do zmiennej przechowuj¹cej iloœæ liczb
 */
void getLCGParams(int& a, int& c, int& m, int& seed, int& n);

/*
 * Pobiera uproszczone parametry dla Addytywnej Metody Kongruencyjnej
 * @param m Referencja do zmiennej przechowuj¹cej modu³
 * @param n Referencja do zmiennej przechowuj¹cej iloœæ liczb
 */
void getAdditiveParams(int& m, int& n);

#endif // MENU_H