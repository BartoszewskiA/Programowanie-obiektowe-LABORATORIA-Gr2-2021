#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <sstream>

using namespace std;

struct cios
{
    int atak_fizyczny = 0;
    int atak_magiczny = 0;
    bool podstepny_atak = false;
};

//----------------------------------------------------------

const int ZYCIE = 200;
class postac
{
protected:
    string imie;
    int zycie = ZYCIE;

public:
    postac(string Imie) : imie(Imie) {}
    int get_zycie() { return zycie; }
    virtual cios zadanie_ciosu() = 0;
    virtual void przyjecie_ciosu(cios c) = 0;
    virtual string przedstaw_sie() = 0;
    virtual string stan_postaci() = 0;
};

//----------------------------------------------------------

class barbarzynca : public postac
{
protected:
    int atak_fizyczny = 25;
    int atak_magiczny = 0;
    int obrona_fizyczna = 20;
    int obrona_magiczna = 0;
    int szal = 0;

public:
    barbarzynca(string Imie) : postac(Imie) {}
    cios zadanie_ciosu()
    {
        cios c;
        int uderzenie = this->atak_fizyczny * ((rand() % 101) / 100.0);
        szal = ZYCIE - zycie;
        uderzenie = uderzenie + szal / 10;
        c.atak_fizyczny = uderzenie;
        return c;
    }
    void przyjecie_ciosu(cios c)
    {
        if (c.podstepny_atak)
        {
            zycie -= c.atak_fizyczny;
            zycie -= c.atak_magiczny;
        }
        else
        {
            zycie -= c.atak_fizyczny - (obrona_fizyczna * ((rand() % 101) / 100.0));
            zycie -= c.atak_magiczny - (obrona_magiczna * ((rand() % 101) / 100.0));
        }
    }
    string przedstaw_sie()
    {
        stringstream temp;
        temp << imie << " barbarzynca";
        return temp.str();
    }
    string stan_postaci()
    {
        stringstream temp;
        temp << "Zycie: " << zycie << "Szal: " << szal;
        return temp.str();
    }
};

//----------------------------------------------------------

class mag : public postac
{
protected:
    int atak_fizyczny = 5;
    int atak_magiczny = 25;
    int obrona_fizyczna = 0;
    int obrona_magiczna = 20;
    int mana = 300;
    int odnawianie_many = 2;

public:
    mag(string Imie) : postac(Imie) {}
    cios zadanie_ciosu()
    {
        cios c;
        if (mana > 0)
        {
            int zaklecie = this->atak_magiczny * ((rand() % 101) / 100.);
            mana -= zaklecie / 2;
            c.atak_magiczny = zaklecie;
        }
        else
        {
            c.atak_fizyczny = this->atak_fizyczny * ((rand() % 101) / 100.0);
        }
        mana += odnawianie_many;
        return c;
    }
    void przyjecie_ciosu(cios c)
    {
        if (c.podstepny_atak)
        {
            zycie -= c.atak_fizyczny;
            zycie -= c.atak_magiczny;
        }
        else
        {
            int zaklecie_ochronne;
            if (mana > 0)
            {
                zaklecie_ochronne = (obrona_magiczna + obrona_fizyczna) * ((rand() % 101) / 100);
                mana -= zaklecie_ochronne / 2;
            }
            else
            {
                zaklecie_ochronne = (obrona_fizyczna) * ((rand() % 101) / 100);
            }
            zycie -= c.atak_fizyczny - zaklecie_ochronne / 2;
            zycie -= c.atak_magiczny - zaklecie_ochronne * 2;
            mana += odnawianie_many;
        }
    }
    string przedstaw_sie()
    {
        stringstream temp;
        temp << imie << " mag";
        return temp.str();
    }
    string stan_postaci()
    {
        stringstream temp;
        temp << "Zycie: " << zycie << "Mana: " << mana;
        return temp.str();
    }
};

void starcie(postac *p1, postac *p2)
{
    cios c;

    while (p1->get_zycie() > 0 && p2->get_zycie() > 0)
    {
        c = p1->zadanie_ciosu();
        cout << c.atak_fizyczny << ";" << c.atak_magiczny << ";" << c.podstepny_atak << endl;
        p2->przyjecie_ciosu(c);
        cout << p2->przedstaw_sie() << " " << p2->stan_postaci() << endl;
        //kontratak
        c = p2->zadanie_ciosu();
        cout << c.atak_fizyczny << ";" << c.atak_magiczny << ";" << c.podstepny_atak << endl;
        p1->przyjecie_ciosu(c);
        cout << p1->przedstaw_sie() << " " << p1->stan_postaci() << endl;
    }
}

int main()
{
    srand(time(NULL));

    postac *druzyna_A[3] = {
        new barbarzynca("Conan"),
        new mag("Gandalf"),
        new mag("Dumbledor")};
    postac *druzyna_B[3] = {
        new mag("Saruman"),
        new barbarzynca("Gora"),
        new mag("Maogana")};

    starcie(druzyna_A[0], druzyna_B[0]);


    return 0;
}