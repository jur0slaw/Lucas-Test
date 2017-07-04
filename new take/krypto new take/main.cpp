#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

struct pojemnik{
    int czynnik;
    int krotnosc;
};

struct zapis{
    pojemnik tab[256];
    int ilosc = 0;

    void dodaj(int x){
        int i=0;
        while(i<ilosc){
            if(x==tab[i].czynnik){
                tab[i].krotnosc++;
                break;
            }
            i++;
        }
        if(i==ilosc){
            tab[ilosc].czynnik=x;
            tab[ilosc].krotnosc=1;
            ilosc++;
        }

    }
    void wypisz_czynniki(){
        cout << "(";
        for(int i=0;i<ilosc;i++){
            cout << tab[i].czynnik;
            if(i!=ilosc-1){
                cout << ",";
            }
        }
        cout << ")";
    }
    void wypisz_krotnosci(){
        cout << "(";
        for(int i=0;i<ilosc;i++){
            cout << tab[i].krotnosc;
            if(i!=ilosc-1){
                cout << ",";
            }
        }
        cout << ")";
    }
};

void faktoryzacja(int d,zapis &foo){
    double y;
    double x = floor(sqrt(d));
    if(x==sqrt(d)){
        faktoryzacja((int)x,foo);
        faktoryzacja((int)x,foo);
    }else{
        x++;
        while(x<(d+1)/2){
            y=x*x-d;
            if(y>0 and sqrt(y)==floor((sqrt(y)))){
                int a,b;
                a = x+sqrt(y);
                b = x-sqrt(y);
                faktoryzacja(a,foo);
                faktoryzacja(b,foo);
                break;
            }else{
                x++;
            }
        }
        if(x>=(d+1)/2){
            foo.dodaj(d);
        }
    }
}

int potegowanie_modulo(int wykladnik, int podstawa, int modulo){

    long int temp = wykladnik;
    int wykladnik_bin[64];
    memset(wykladnik_bin,0,64*sizeof(int));

    int i=0;
    while(temp>0){
        wykladnik_bin[63-i]=temp%2;
        temp=temp/2;
        i++;
    }

    i = 0;
    while(wykladnik_bin[i]==0){
        i++;
    }

    int pierwszy_adres=i;
    int potegi_modulo[64];
    potegi_modulo[63]=podstawa%modulo;

    for(i=62;i>=pierwszy_adres;i--){
        potegi_modulo[i]=(potegi_modulo[i+1]*potegi_modulo[i+1])%modulo;

    }
    long int wynik=1;

    for(i=pierwszy_adres;i<64;i++){
        if(wykladnik_bin[i]==1){
            wynik=(wynik*potegi_modulo[i])%modulo;
        }
    }
    return wynik;
}

int main()
{
    zapis foo;

    int a;
    int d;
    cout << "Podaj liczbe wejsciowa:" << endl;
    cin >> a ;
    a--;
    d=a;


    while(d%2==0){
        d/=2;
        foo.dodaj(2);
    }

    if(d>1){
        faktoryzacja(d,foo);
    }
    cout << "Czynniki liczby " << a << " to: ";
    foo.wypisz_czynniki();
    cout << " o krotnosciach: ";
    foo.wypisz_krotnosci();

    a++;
    int q;
    int flag=0;

    cout << endl << endl << "Podaj liczbe q: " << endl;

    cin >> q;

    if(!(potegowanie_modulo(a-1,q,a)==1)){
       flag = 1;
    }

    cout << q << "^" << a-1 << " = " << potegowanie_modulo(a-1,q,a) << "(mod " << a << ")" << endl;

    for(int i=0;i<foo.ilosc;i++){
       cout << q << "^" << a-1 << "/" << foo.tab[i].czynnik << " = " << potegowanie_modulo((a-1)/foo.tab[i].czynnik,q,a) << "(mod " << a << ")" << endl;
        if(!(potegowanie_modulo((a-1)/foo.tab[i].czynnik,q,a)==1)){
            flag = 1;
        }
    }

    if(flag==1){
        cout << "Test nie rozstrzyga czy liczba " << a << " jest pierwsza.";
    }else{
        cout << "Liczba " << a << "jest pierwsza!";
    }
    return 0;
}
