#include <iostream>
#include <string.h>

using namespace std;

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



    return 0;
}
