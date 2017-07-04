#include <iostream>
#include <cmath>

using namespace std;

struct dz
{
    int dzielnik = 0;
    int krotnosc = 0;
};

typedef dz dz;

void wypisz_wynik(dz * tab,int liczba_dzielnikow, int a)
{

    cout << "liczba a ma nastepujace dzielniki: (";
    for(int i = 0; i<liczba_dzielnikow; i++)
    {
        cout << tab[i].dzielnik ;
        if(i!=liczba_dzielnikow-1)
            cout <<   ",";
    }
    cout << "). o krotnosciach; (";
    for(int i = 0; i<liczba_dzielnikow; i++)
    {
        cout << tab[i].krotnosc ;
        if(i!=liczba_dzielnikow-1)
            cout << ",";

    }
    cout << ")";
}





int main()
{
    int a;
    cin >> a ;
    int d = a;
    int i = 0;
    while(d%2==0)
    {
        d/=2;
        i++;
    }

    cout << "Liczba a jest w postaci:" << a << "=2^"<< i << "*" << d << endl;


    int x = floor(sqrt(d));
    int y;
    int liczba_dzielnikow=0;
    dz tab[4];

    if(i>0)
    {
        tab[liczba_dzielnikow].dzielnik=2;
        tab[liczba_dzielnikow].krotnosc=i;
        liczba_dzielnikow++;
    }

    //DLA D

    if((double)x!=sqrt(d))
    {
        x=x+1;
    }
    else
    {
        tab[liczba_dzielnikow].dzielnik=x;
        tab[liczba_dzielnikow].krotnosc=2;
        liczba_dzielnikow++;

    }

    if( (double)x==sqrt(d) && tab[1].dzielnik==1){
        wypisz_wynik(tab,liczba_dzielnikow-1,a);
        return 0;
    }



    int warunek = 0;

    while(x<(d+1)/2)
    {
        y=x*x-d;
        if(y>0 && (double)floor(sqrt(y))==sqrt(y))
        {
            warunek = 1;
            break;
        }
        else
        {
            x=x+1;
        }

    }



    if(warunek == 0)
    {
        tab[liczba_dzielnikow].dzielnik = d;
        tab[liczba_dzielnikow].krotnosc = 1;
        liczba_dzielnikow++;
        wypisz_wynik(tab,liczba_dzielnikow,a);
        return 0;

    }


    int d_prim = (int)(x+sqrt(y));
    int d_bis  = (int)(x-sqrt(y));


    x=floor(sqrt(d_prim));
     d = d_prim;


    //DLA D'

    if((double)x!=sqrt(d))
    {
        x=x+1;
    }
    else
    {
        for(i=0; i<liczba_dzielnikow-1; i++)
        {
            if(tab[i].dzielnik==x)
            {
                break;
            }
            if(tab[i].dzielnik!=x)
            {
                liczba_dzielnikow++;
            }
            tab[i].dzielnik=x;
            tab[i].krotnosc+=2;
        }
    }



    warunek = 0;


    while(x<(d+1)/2)
    {
        y=x*x-d;
        if(y>0 && (double)floor(sqrt(y))==sqrt(y))
        {
            warunek = 1;
            break;
        }
        else
        {
            x=x+1;
        }
    }

    if(warunek==0)
    {
        for(i=0; i<liczba_dzielnikow-1; i++)
        {
            if(tab[i].dzielnik==d)
            {
                break;
            }
        }
        if(tab[i].dzielnik!=d)
        {
            liczba_dzielnikow++;
        }

        tab[i+1].dzielnik=d;
        tab[i+1].krotnosc+=1;

    }
    else
    {
        d=x+(int)sqrt(y);

        for(i=0; i<liczba_dzielnikow-1; i++)
        {
            if(tab[i].dzielnik==d)
            {
                break;
            }
        }
        if(tab[i].dzielnik!=d)
        {
            liczba_dzielnikow++;
        }
        tab[i+1].dzielnik=d;
        tab[i+1].krotnosc+=1;


        d=x-sqrt(y);

        for(i=0; i<liczba_dzielnikow-1; i++)
        {
            if(tab[i].dzielnik==d)
            {
                break;
            }
        }
        if(tab[i].dzielnik!=d)
        {
            liczba_dzielnikow++;
        }
        tab[i+1].dzielnik=d;
        tab[i+1].krotnosc+=1;

    }




    d=d_bis;
    x = floor(sqrt(d_bis));

    //D:A D''

    if((double)x!=sqrt(d))
    {
        x=x+1;
    }

    warunek = 0;

    while(x<(d+1)/2)
    {
        y=x*x-d;
        if(y>0 && (double)floor(sqrt(y))==sqrt(y))
        {
            warunek = 1;
            break;
        }
        else
        {
            x=x+1;
        }

    }

    if(warunek==0)
    {
        for(i=0; i<liczba_dzielnikow-1; i++)
        {
            if(tab[i].dzielnik==d)
            {
                break;
            }
        }
        if(tab[i].dzielnik!=d)
        {
            liczba_dzielnikow++;
        }
        tab[i+1].dzielnik=d;
        tab[i+1].krotnosc+=1;
    }

    else
    {
        d=x+(int)sqrt(y);

        for(i=0; i<liczba_dzielnikow-1; i++)
        {
            if(tab[i].dzielnik==d)
            {
                break;
            }
        }
        if(tab[i].dzielnik!=d)
        {
            liczba_dzielnikow++;
        }

        tab[i+1].dzielnik=d;
        tab[i+1].krotnosc+=1;


        d=x-sqrt(y);

        for(i=0; i<liczba_dzielnikow-1; i++)
        {
            if(tab[i].dzielnik==d)
            {
                break;
            }
        }
        if(tab[i].dzielnik!=d)
        {
            liczba_dzielnikow++;
        }
        tab[i+1].dzielnik=d;
        tab[i+1].krotnosc+=1;
    }


    wypisz_wynik(tab,liczba_dzielnikow,a);


    return 0;
}
