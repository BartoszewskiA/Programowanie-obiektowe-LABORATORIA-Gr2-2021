#include <iostream>
#include <sstream>

using namespace std;

class RGB;
class ARGB;

class RGB
{
private:
    int R;
    int G;
    int B;

public:
    RGB(int r = 0, int g = 0, int b = 0) : R(r), G(g), B(b) {}
    string toString() // R=... G=... B=...
    {
        stringstream temp;
        temp << "R=" << R << " G=" << G << " B=" << B << " ";
        return temp.str();
    }
    friend ARGB* dodaj(RGB* k1, ARGB* k2);
    friend ARGB* dodaj(ARGB* k1, RGB* k2);
    // friend ARGB* dodaj(ARGB* k1, ARGB* k2);
    friend ARGB* dodaj(RGB* k1, RGB* k2);
};

class ARGB
{
private:
    int A;
    int R;
    int G;
    int B;

public:
    ARGB(int a = 0, int r = 0, int g = 0, int b = 0) : A(a), R(r), G(g), B(b) {}
    string toString() // R=... G=... B=...
    {
        stringstream temp;
        temp << "A="<<A<<" R=" << R << " G=" << G << " B=" << B << " ";
        return temp.str();
    }
    friend ARGB* dodaj(RGB* k1, ARGB* k2);
    friend ARGB* dodaj(ARGB* k1, RGB* k2);
    friend ARGB* dodaj(ARGB* k1, ARGB* k2);
    friend ARGB* dodaj(RGB* k1, RGB* k2);
};


ARGB* dodaj(RGB* k1, ARGB* k2)
{
    ARGB* temp = new ARGB;
    temp->A = (255 + k2->A) / 2; // obiekt RGB jest nieprzezroczysty - domyślnie A = 255
    temp->R = (k1->R + k2->R) / 2;
    temp->G = (k1->G + k2->G) / 2;
    temp->B = (k1->B + k2->B) / 2;
    return temp;
}

ARGB* dodaj(ARGB* k1, RGB* k2)
{
    ARGB* temp = new ARGB;
    temp->A = (k1->A + 255) / 2; // obiekt RGB jest nieprzezroczysty - domyślnie A = 255
    temp->R = (k1->R + k2->R) / 2;
    temp->G = (k1->G + k2->G) / 2;
    temp->B = (k1->B + k2->B) / 2;
    return temp;
}

ARGB* dodaj(ARGB* k1, ARGB* k2)
{
    ARGB* temp = new ARGB;
    temp->A = (k1->A + k2->A) / 2;
    temp->R = (k1->R + k2->R) / 2;
    temp->G = (k1->G + k2->G) / 2;
    temp->B = (k1->B + k2->B) / 2;
    return temp;
}

ARGB* dodaj(RGB* k1, RGB* k2)
{
    ARGB* temp = new ARGB;
    temp->A = 255;
    temp->R = (k1->R + k2->R) / 2;
    temp->G = (k1->G + k2->G) / 2;
    temp->B = (k1->B + k2->B) / 2;
    return temp;
}


int main()
{
    RGB *p1 = new RGB(20, 30, 40);
    ARGB *p2 = new ARGB(0, 30, 40, 10);
    ARGB* wynik = dodaj(p2,p1);
    cout<<wynik->toString();
    delete p1;
    delete p2;
    delete wynik;
    return 0;
}