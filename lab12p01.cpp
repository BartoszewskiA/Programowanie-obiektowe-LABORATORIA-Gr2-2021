#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
class zespolona
{
private:
    double r; //część rzeczywista
    double u; //część urojona
public:
    zespolona(double R = 0, double U = 0) : r(R), u(U) {}
    friend ostream &operator<<(ostream &str, zespolona x);
    friend istream &operator>>(istream &str, zespolona &x);
};

ostream &operator<<(ostream &str, zespolona x)
{
    if (x.r == 0 && x.u == 0)
        str << 0;
    else
    {
        if (x.r != 0)
            str << x.r;
        if (x.u > 0 && x.r != 0)
            str << "+";
        if (x.u != 0)
            str << x.u << "i";
    }

    return str;
}

istream &operator>>(istream &str, zespolona &x)
{
    string temp;
    int poz_zn = 0;
    str>>temp;
    // 9+9i  9-9i  -9+9i  -9-9i  9  -9   9i  -9i - możliwe przypadki
    //tylko część rzeczywista [9  -9]
    if (temp[temp.length()-1]!='i')
    {
        x.r = atof(temp.c_str());
        x.u = 0;
    }
    else  // 9+9i  9-9i  -9+9i  -9-9i   9i  -9i
    {
        for (int i=0; i<temp.length(); i++)
            if (temp[i]=='+' || temp[i]=='-')
                poz_zn=i;
        if (poz_zn==0) // 9i  -9i - tylko część urojona
        {
            x.r = 0;
            temp = temp.substr(0,temp.length()-1);
            x.u = atof(temp.c_str());
        }
        else // 9+9i  9-9i  -9+9i  -9-9i - pełna postać
        {
            string tempR = temp.substr(0,poz_zn);
            x.r = atof(tempR.c_str());
            string tempU = temp.substr(poz_zn, temp.length()-1);
            x.u = atof(tempU.c_str());
        }
    }
    return str;
}

int main()
{
    // zespolona a(10, 3), b(0, 0), c(0, 5), d(-3, -5), e(3, 0);
    // cout << a << endl
    //      << b << endl
    //      << c << endl
    //      << d << endl
    //      << e << endl;

    zespolona x;
    cout<<"x=";
    cin>>x;
    cout<<"Wczytano: "<< x;
    return 0;
}