#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <locale.h>
#include "Gracz.h"
#include "Kolo.h"
#include "Menu.h"
#include "Haslo.h"

using namespace std;


int main()
{
    Menu menu;
    Gracz gracze[3];

    gracze[0].imie = "Bryanusz";
    gracze[1].imie = "Jessica ";
    gracze[2].imie = "Nepomucen";  

    srand(time(NULL));

    Menu();

    exit(0);

    menu.textPlayers();
    Beep(523, 500);
}