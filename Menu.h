#include <string>
using namespace std;

class Menu {
public:
	int kolejka = 0;
	int suma = 0;
	char literka;
	int sa_spolgloski = 0;
	int kwota = 0;
	int zgadl = 0;
	char wybor;
	string proba;
	string rezultat;
	void textPlayers();
	char WczytajZnak();
	char WczytajWybor();
	bool operator< (int Menu& i, int x) {};
	void operator++();
	Menu();
};