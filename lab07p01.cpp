#include <iostream>
#include <sstream>

using namespace std;

class RGB
{
private:
    int R;
    int G;
    int B;

public:
    static int ile;
    RGB(int r = 0, int g = 0, int b = 0) : R(r), G(g), B(b)
    {
        ile++;
        cout << endl
             << "utworzono obiekt" << endl;
    }
    string toString(); // R=... G=... B=...
    friend RGB dodaj(RGB k1, RGB k2);
    friend RGB* dodaj_dynamicznie(RGB* k1, RGB* k2);
    ~RGB() { cout << endl
                  << "usunieto obiekt" << endl; }
};

int RGB::ile = 0;

string RGB::toString()
{
    stringstream temp;
    temp << "R=" << R << " G=" << G << " B=" << B << " ";
    return temp.str();
}

RGB dodaj(RGB k1, RGB k2)
{
    RGB temp;
    temp.R = (k1.R + k2.R) / 2;
    temp.G = (k1.G + k2.G) / 2;
    temp.B = (k1.B + k2.B) / 2;
    return temp;
}

RGB* dodaj_dynamicznie(RGB* k1, RGB* k2)
{
    RGB* temp = new RGB;
    temp->R = (k1->R + k2->R) / 2;
    temp->G = (k1->G + k2->G) / 2;
    temp->B = (k1->B + k2->B) / 2;
    return temp;
}

int main()
{
    // RGB p1(10, 20, 30), p2(20, 40, 50);
    // RGB wynik = dodaj(p1, p2);
    // cout << "wynik: " << wynik.toString();
    RGB* p1 = new RGB(20,30,40);
    RGB* p2 = new RGB(30,40,10);

    RGB* wynik = dodaj_dynamicznie(p1,p2);

    cout<<wynik->toString();

    delete p1;
    delete p2;
    delete wynik;


    cout << endl
         << "Utworzono " << RGB::ile << " obiektow";
    return 0;
}