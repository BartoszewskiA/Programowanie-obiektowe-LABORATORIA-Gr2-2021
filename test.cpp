#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

class napis
{
private:
    string lancuch;
    string d;
    int size;

public:
    napis(string lancuch)
    {
        fstream plik;
        plik.open("napis.txt", ios::app);
        plik << lancuch << endl;
        plik.close();
    }

    void zapis()
    {
        cout << "Podaj tekst :" << endl;
        getline(cin, d);
        fstream plik;
        plik.open("napis.txt", ios::app);
        plik << d << endl;
        plik.close();
    }

    void odczyt()
    {
        cout << "Twoj tekst to :" << endl;
        fstream plik;
        plik.open("napis.txt", ios::in);
        getline(plik, d);
        plik.close();
    }

    int dlugosc()
    {
        size = d.size();
        return size;
    }

    void wypisz()
    {
        cout << "Twoj tekst to: " << d << endl;
    }

    void destruct()
    {
        cout << "Dane zostały usunięte!" << endl;
        remove("napis.txt");
    }
};

int main()
{
    napis(tab[10]) = {
        {"Lorem Ipsum is simply dummy text of the printing and typesetting industry"},
        {"Lorem Ipsum has been the industry's standard dummy text ever since the 1500s"},
        {"when an unknown printer took a galley of type and scrambled it to make a type specimen book"},
        {"It has survived not only five centuries, but also the leap into electronic typesetting"},
        {"Lorem Ipsum is simply dummy text of the printing and typesetting industry"},
        {"Lorem Ipsum has been the industry's standard dummy text ever since the 1500s"},
        {"when an unknown printer took a galley of type and scrambled it to make a type specimen book"},
        {"It has survived not only five centuries, but also the leap into electronic typesetting"},
        {"Lorem Ipsum is simply dummy text of the printing and typesetting industry"},
        {"Lorem Ipsum has been the industry's standard dummy text ever since the 1500s"}};

    //tab[1].zapis();
    tab[1].odczyt();
    tab[1].wypisz();

    tab[4].odczyt();
    tab[4].wypisz();

    tab[8].odczyt();
    tab[8].wypisz();

    tab[1].destruct();
    return 0;
}