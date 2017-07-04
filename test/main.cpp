
#include <iostream>

#include <math.h>

using namespace std;



void faktoryzacja(unsigned int k)

{

  unsigned long x,y,r,u,n;

  x = (unsigned long)(sqrt(k));

  do

  {

    r = x * x - k;

    y = (unsigned long)floor(sqrt(r));

    if(r == y * y)

    {

      u = x + y;

      n = x - y;

      if(n == 1)

      break;

      faktoryzacja(u);

      faktoryzacja(n);

      return;

    }

    x++;

  } while(x + y < k);

  cout <<k << "\t";

}

int main()

{

  unsigned int k; // liczba rozkladana na czynniki pierwsze

  cout<<"\t\t\n\nPodaj liczbe:  ";

  cin >> k;

  cout<<"\n\n";

  while(k % 2 == 0)

  {

    k /= 2;

    cout << 2 << "\t";

  }

  if(k > 1)

  faktoryzacja(k);

  cout << endl;


  cin.ignore();

 //  getchar();

  return 0;
}
