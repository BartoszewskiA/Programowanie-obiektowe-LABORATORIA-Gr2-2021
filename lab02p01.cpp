#include <iostream>
#include <ctime>

using namespace std;

class osoba
{
private:
    string imie;
    string nazwisko;
    int rok_urodzenia;

public:
    // settery
    void setImie(string im) { imie = im; }
    void setNazwisko(string nazw) { nazwisko = nazw; }
    void setRok_urodzenia(int rok) { rok_urodzenia = rok; }
    void setWiek(int w);
    // gettery
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    int getRok_urodzenia() { return rok_urodzenia; }
    int getWiek();
};

void osoba::setWiek(int w)
{
    time_t czas = time(NULL);
    tm *czasLokalny = localtime(&czas);
    rok_urodzenia = (1900 + czasLokalny->tm_year) - w;
}

int osoba::getWiek()
{
    time_t czas = time(NULL);
    tm *czasLokalny = localtime(&czas);
    return (1900 + czasLokalny->tm_year) - rok_urodzenia;
}

int main()
{
    osoba *p = new osoba;
    string s;
    int w;

    cout << "imie: ";
    cin >> s;
    p->setImie(s);
    cout << "nazwisko: ";
    cin >> s;
    p->setNazwisko(s);
    cout << "wiek: ";
    cin >> w;
    p->setWiek(w);

    cout << p->getNazwisko() << " " << p->getImie() << " " << p->getWiek() << " lat urodzony w: "<<p->getRok_urodzenia();

    delete p;
    return 0;
}