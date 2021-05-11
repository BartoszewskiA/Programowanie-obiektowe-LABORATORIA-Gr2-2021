#include <iostream>

using namespace std;

class liczba
{
private:
    int x;

public:
    static int ile;
    static int suma;
    liczba(int liczba = 0) : x(liczba)
    {
        ile++;
        suma += x;
    }
    ~liczba()
    {
        ile--;
        suma -= x;
    }
    int getLiczba() { return x; }
    static int getIle() { return ile; }
    static int getSuma() { return suma; }
    void setLiczba(int liczba)
    {
        suma -= x;
        x = liczba;
        suma += x;
    }
};

int liczba::ile = 0;
int liczba::suma = 0;

int main()
{
    // liczba a(10), b(50), c(100), d(200);
    // cout<<a.ile;
    // cout<< liczba::getIle();

    liczba *p1 = new liczba(100);
    liczba *p2 = new liczba(200);
    liczba *p3 = new liczba(300);

    p1->setLiczba(1000);

    cout << liczba::ile << " " << liczba::suma << endl;

    delete p1;
    delete p2;
    delete p3;

    cout << liczba::ile << " " << liczba::suma << endl;
    return 0;
}