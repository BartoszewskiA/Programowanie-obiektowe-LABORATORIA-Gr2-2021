#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>

using namespace std;

class liczba
{
private:
    int x;
    int Id;
    time_t czas_utworzenia;
    void zapisz_do_pliku(int akcja); //akcja = 1 -> utworzenie
                                     //akcja != 1 -> usunięcie
public:
    static int ile;
    static time_t start_programu;
    liczba(int liczba = 0) : x(liczba)
    {
        Id = ++ile;
        czas_utworzenia = time(NULL);
        zapisz_do_pliku(1);
    }
    ~liczba()
    {
        zapisz_do_pliku(0);
    }
    int getLiczba() { return x; }
    int getId() { return Id; }
    void setLiczba(int liczba) { x = liczba; }
};
void liczba::zapisz_do_pliku(int akcja)
{
    fstream plik;
    plik.open("lab06p01.log", ios::app);
    time_t czas = time(NULL);
    tm * czas_l = localtime(&czas);
    plik<<"obiekt: "<<Id;
    if (akcja==1) 
        plik<<" utworzono ";
    else
        plik<<" usunieto ";
    plik<<czas_l->tm_hour<<":"<<czas_l->tm_min<<":"<<czas_l->tm_sec<<"; ";
       if (akcja==1) 
        plik<<"po "<<czas - start_programu <<" s. od uruchomienia programu"<<endl;
    else
        plik<<"istnial "<<czas - czas_utworzenia<<" s."<<endl;
    plik.close();
}
int liczba::ile = 0;
time_t liczba::start_programu;


int main()
{
    liczba::start_programu = time(NULL);
    
    liczba* p1 = new liczba(100);
        cout<<"Press any key";
        getch();
    liczba* p2 = new liczba(200);
        cout<<"Press any key";
        getch();
    delete p1;
        cout<<"Press any key";
        getch();
    delete p2;
    return 0;
}