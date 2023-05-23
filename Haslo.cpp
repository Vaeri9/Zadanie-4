#include <iostream>
#include <fstream> 
#include <cassert>
#include "Haslo.h"

int i;

void Haslo::operator++() {
    i++;
    return *this;
};

Haslo::Haslo() {
    ifstream strum;                                         
    strum.open("dane.txt");

    setlocale(LC_CTYPE, "Polish");

    while (!strum.eof())
    {
        string s;
        //strum >> s;
        getline(strum, s);
        //cout << s << endl;
        hasla.push_back(s);

    }

    strum.close();

    // for (i = 0; i < hasla.size(); i++)
     //    cout << hasla[i] << endl;

    for (string item : hasla)
        cout << item << endl;

    cout << endl << endl;

    assert(hasla.size() > 0);
    j = rand() % hasla.size(); // losujemy j-te haslo z przedzialu 0 ... size - 1
    //cout << hasla[j];

    haslo = hasla[j];
    n = haslo.size();


    for (i = 0; i < n; i++)
    {
        if (haslo[i] == ' ')
            maska[i] = 0;
        else
            maska[i] = 1;
    }
};

int Haslo::jestSamogloska(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
        return 1;
    else
        return 0;

};