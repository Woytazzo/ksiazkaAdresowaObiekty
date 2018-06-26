#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "uzytkownicy.h"

using namespace std;

int main()
{
    vector <Uzytkownik> uzytkownicy;
    cout<<uzytkownicy.size()<<endl;
    Uzytkownik uzytkownik;
//    uzytkownicy=wczytanieUzytkownikowZPliku();
    cout<<uzytkownicy.size()<<endl;
    uzytkownik.rejestracja(uzytkownicy);
    return 0;
}
