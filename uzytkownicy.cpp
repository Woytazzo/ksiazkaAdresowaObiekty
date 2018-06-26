#include <iostream>
#include "uzytkownicy.h"

using namespace std;

vector <Uzytkownik> Uzytkownik::rejestracja(vector <Uzytkownik> &uzytkownicy) {
    string login;

    while(1) {
        //system("cls");
        cout<<"Zaproponuj swoj unikalny login:"<<endl;
        cin>>login;
        if(uzytkownicy.size()>0) {
            for (int i=0; i<uzytkownicy.size(); i++) {
                if (uzytkownicy[i].login==login) {
                    cout<<"Taki login istnieje juz w bazie! Musisz wybrac inny."<<endl;
                    Sleep(1300);
                    break;
                } else if (uzytkownicy[i].login!=login && i==(uzytkownicy.size()-1)){
                    uzytkownicy=podanieHaslaPodczasRejestracji(login, uzytkownicy);
                    return uzytkownicy;
                }
            }
        } else {uzytkownicy=podanieHaslaPodczasRejestracji(login, uzytkownicy);
        return uzytkownicy;}
    }
}
void Uzytkownik::dodanieDoPlikuJednegoUzytkownika(Uzytkownik nowy) {
    fstream plik;
    plik.open("Uzytkownicy.txt", ios::out | ios::app);
    plik<<nowy.id<<"|"<<nowy.login<<"|"<<nowy.haslo<<"|"<<endl;
    plik.close();
}

vector <Uzytkownik> Uzytkownik::podanieHaslaPodczasRejestracji(string login, vector <Uzytkownik> &uzytkownicy) {
    Uzytkownik nowy;
    string haslo;
    system("cls");
    while(1) {
        cout<<"Podaj haslo, skladajace sie z conajmniej 5 znakow:"<<endl;
        cin>>haslo;

        if(haslo.length()>=5) {
            nowy.haslo=haslo;
            nowy.login=login;
            nowy.id=uzytkownicy.size()+1;
            uzytkownicy.push_back(nowy);

            system("cls");
            cout<<"Konto zostalo zalozone."<<endl;
            dodanieDoPlikuJednegoUzytkownika(nowy);
            Sleep(1300);
            return uzytkownicy;
        } else {
            cout<<"wprowadzone haslo jest zbyt krotkie!"<<endl;
            Sleep(1300);
        }
    }
}

Uzytkownik Uzytkownik::pobranieUzytkownikaZJednejLinii(string liniaZPliku) {

    string roboczy;
    int iloscPrzerywnikow=0;
    string literaDoDodania;
    Uzytkownik uzytkownikDoDodania;
    int id;
    string login, haslo;

    for (int i=0; i<liniaZPliku.length(); i++) {
        if (liniaZPliku[i]!=124) {
            literaDoDodania=liniaZPliku[i];
            roboczy.insert(roboczy.length(), literaDoDodania);
        } else if (liniaZPliku[i]==124) {
            iloscPrzerywnikow++;

            switch(iloscPrzerywnikow) {
            case 1:
                uzytkownikDoDodania.id = atoi(roboczy.c_str());
                break;
            case 2:
                uzytkownikDoDodania.login = roboczy;
                break;
            case 3:
                uzytkownikDoDodania.haslo = roboczy;
                break;
            }
            roboczy="";
        }
    }
    return uzytkownikDoDodania;
}

vector <Uzytkownik> Uzytkownik::wczytanieUzytkownikowZPliku() {
    Uzytkownik uzytkownikRoboczy;
    vector <Uzytkownik> uzytkownicy;
    string liniaZPliku;
    fstream plik;

    plik.open("Uzytkownicy.txt", ios::in);

    if (plik.good() == true) {
        while(getline(plik,liniaZPliku)) {
            uzytkownikRoboczy=pobranieUzytkownikaZJednejLinii(liniaZPliku);

            uzytkownicy.push_back(uzytkownikRoboczy);
        }
        plik.close();
    }
    return uzytkownicy;
}

