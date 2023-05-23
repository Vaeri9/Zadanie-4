#include <cstring>
#include <string>
using namespace std;

class Gracz {
public:
    string imie;
    int kasa = 0;
    int portfel = 0; //kasa z wygranych rund

    friend class Menu;
};
