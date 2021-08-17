

#include <iostream>
#include <cmath>
using namespace std;


#define  M_PI  asin(0.5)


class kolo
{
protected:
    int r;
public:
    kolo(int promien =1): r(promien){}
    double obwod( int r) { return 2 * M_PI * r; }
    double pole(int r) { return M_PI * r * r; }

    friend int operator*(kolo& k, int r) { k.r *= r; return k.r; }
    int operator++(int r) { r += 1; return r; }
     bool operator==(kolo& k) { return r == k.r; }

     friend void setR(kolo& k, int R) { k.r=R; }
  
};

class ostroslup: public kolo {
protected:
    int h;
public:
    ostroslup(int wysokosc=1) :h(wysokosc){}
    double pole() { return ((M_PI * r * r)+(M_PI*h*(sqrt(r*r+h*h)))); }
    double objetosc(){ return ((M_PI * r * r * h)/3); }
};






int main()
{

    cout <<"wynik" ;
    kolo p1(2);
    cout << p1.obwod(2)<<endl;

    return 0;
}

