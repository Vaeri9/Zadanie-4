#include "Menu.h"
#include "Gracz.h"
#include <iostream>
#include "Haslo.h"
#include "Kolor.h"
using namespace std;



int i;

bool Menu::operator< (int Menu& i, int x) {};

void Menu::operator++() {
    i++;
    return *this;
};

void Menu::textPlayers()
{
    cout << "\n";
    for (i = 0; i < 3; i++) {
        if (i == kolejka) {
            WyswietlKolor(1);
        }
        cout << gracze[i].imie << "\t" << gracze[i].kasa << "\n";
        WyswietlKolor(4);

    }
    cout << "\n";
};

char Menu::WczytajZnak()
{
    string letter;
    cin >> letter;

    while (letter.length() != 1)
    {
        cout << endl << "Type a single letter and press <enter>: ";
        cin >> letter;
    }

    for (auto& c : letter)  // & zapamietuje modyfikacje w petli & - referencja
        c = toupper(c);

    return letter[0];

};

char Menu::WczytajWybor()
{
    char wybor;
    wybor = WczytajZnak();

    while (wybor != '1' && wybor != '2')
    {
        cout << endl << "Wybierz [1-2]: ";
        cin >> wybor;
    }

    return wybor;

};

Menu::Menu() {
    do
    {
        // cout << "\033[2J";

        WyswietlKolor(2); 
        WyswietlKolor(3);
        for (i = 0; i < n; i++)
        {

            if (maska[i] == 1)
                cout << ".";
            else
                cout << haslo[i];
        }

        cout << "\033[0m";
        cout << endl;


        sa_spolgloski = 0;
        kwota = 0;

        for (i = 0; i < n; i++)
            if ((!jestSamogloska(haslo[i])) && (maska[i]))
            {
                sa_spolgloski = 1;
                break;
            }

        if (sa_spolgloski)
            cout << " -- Spolgloski sa --" << endl;


        //cout << gracze[kolejka].imie << " " << endl;
        textPlayers();

        cout << "1. zgaduj haslo" << endl;
        cout << "2. krecenie kolem" << endl;

        // TODO tylko 1 i 2, nie mozna wprowadzac liter

        wybor = WczytajWybor();

        if (wybor == '1')
        {
            cout << "Podaj haslo" << endl;
            getline(cin >> ws, proba);  // wczytanie z klawiatury string z uwzgl. whitespa
            for (auto& c : proba)  // & zapamietuje modyfikacje w petli & - referencja
                c = toupper(c);
            if (haslo == proba) {
                cout << endl << " !!!!!!!!!! =======   WYGRANA ========== !!!!!!!!!!!!!" << endl;
                gracze[kolejka].portfel += gracze[kolejka].kasa;
                break;
            }
            else
            {
                kolejka = (kolejka + 1) % 3;
                suma = 1;
                cout << endl << " !!!!!!!!!! =======   ZLE ========== !!!!!!!!!!!!!" << endl;
                cout << endl << "=================================================" << endl;
                continue;


            }



        }


        rezultat = "";
        i = rand() % 15;
        if (kolo[i] == 0)
            rezultat = "Strata kolejki";
        if (kolo[i] == -1)
            rezultat = "Bankrut";
        if (rezultat != "") {
            WyswietlKolor(5);
            cout << rezultat << WyswietlKolor(4) << endl;
        }
        else
        {
            WyswietlKolor(1);
            cout << Kolo[i] << WyswietlKolor(4); 
            cout << endl;
            kwota = kolo[i];
        }

        // Strata kolejki i bankrut
        if ((kolo[i] == 0) || (kolo[i] == -1))
        {
            if (kolo[i] == -1) // bankrut
                gracze[kolejka].kasa = 0;

            kolejka = (kolejka + 1) % 3;
            suma = 1;
            cout << endl << "=================================================" << endl;

            // TODO
            // sleep for
            // kupowanie samoglosek

            continue;

        }





        cout << gracze[kolejka].imie << ": Podaj litere" << endl;



        literka = WczytajZnak();


        zgadl = 0;

        if (jestSamogloska(literka))
            cout << "samogloska";
        else
            cout << "spolgloska";
        cout << endl;

        for (i = 0; i < n; i++)
        {
            if ((haslo[i] == literka) && (maska[i] == 1)) {
                maska[i] = 0;
                zgadl++;
            }
        }

        if (zgadl)
        {
            cout << "OK";
            gracze[kolejka].kasa += kwota * zgadl;

            cout << endl << gracze[kolejka].imie << WyswietlKolor(6);
            cout << gracze[kolejka].kasa << WyswietlKolor(4);;


        }
        else {
            cout << "Zle!";
            // strata kolejki
            kolejka = (kolejka + 1) % 3;
            cout << endl << "=================================================" << endl;
            suma = 1;
            continue;
        }




        cout << endl;



        suma = 0;

        for (i = 0; i < n; i++)
        {
            suma += maska[i];
            suma += maska[i];
        }



    } while (suma);
    cout << "BRAWO!";

}