#include <iostream>

using namespace std;

class tablica
{
private:
    int tab[100];

public:
    int const dlugosc = 100;
    tablica(int x=0)
    {
        for(int i=0; i<dlugosc; i++)
            tab[i]=x;
    }

    double getSrednia()
    {
        int suma=0;
        for (int i=0;i<dlugosc; i++)
            suma+=tab[i];
        return suma / (double)dlugosc;
    }
    
    int & operator[](unsigned int index)
    {
        return tab[index];
    }
};

int main()
{
    tablica t1(100);

    cin>>t1[10];

    for (int i=0; i<t1.dlugosc; i++)
        cout<<t1[i]<<" ";
    cout<<endl<<t1.getSrednia();
    return 0;
}