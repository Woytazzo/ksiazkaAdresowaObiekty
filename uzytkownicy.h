#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <stdio.h>

using namespace std;

class Uzytkownik
{
    int id;
    string login, haslo;


    public:

    vector <Uzytkownik> rejestracja(vector <Uzytkownik> &uzytkownicy);
    vector <Uzytkownik> podanieHaslaPodczasRejestracji(string login, vector <Uzytkownik> &uzytkownicy);
    void dodanieDoPlikuJednegoUzytkownika(Uzytkownik nowy);
    vector <Uzytkownik> wczytanieUzytkownikowZPliku();
    Uzytkownik pobranieUzytkownikaZJednejLinii(string liniaZPliku);
};
