using namespace std;

class Kolor {
public:
	int x;
	void WyswietlKolor(int x);
	friend ostream& operator<<(ostream& output);
	
	friend class Menu;
};