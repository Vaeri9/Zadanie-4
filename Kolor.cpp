#include "Kolor.h"
#include <iostream>

ostream& operator<<(ostream& output) {
	output << "\033["
	return output;
}

void Kolor::WyswietlKolor(int x) {
	switch (x) {
		case 1: cout << "1;34m";
			break;
		case 2: cout << "47m";
			break;
		case 3: cout << "31m";
			break;
		case 4: cout << "0m";
			break;
		case 5: cout << "1;31m";
			break;
		case 6: cout << "1;32m ";
			break;
	}
}