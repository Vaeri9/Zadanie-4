#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Haslo {
	public:
	string haslo;
	int maska[100];
	int n;
	int i;
	int j;
	vector<string> hasla;
	void operator++();
	Haslo();
	int jestSamogloska(char c);

	friend class Menu;

};