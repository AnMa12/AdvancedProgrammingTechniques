#include<iostream>
#include<fstream>
using namespace std;
ifstream f("date.in");
int zParcurgere(int x, int y, int marime)
{
    if(marime == 1)
        return 1;

    marime = marime/2;

    if(x < marime && y < marime)
    //cadranul din stanga sus
        return zParcurgere(x, y, marime);

    if(x < marime && y >= marime)
    //cadranul dreapta sus
        return marime*marime +
               zParcurgere(x, y-marime, marime);

    if(x >= marime && y < marime)
    //cadranul stanga jos
        return 2*marime*marime +
               zParcurgere(x-marime, y, marime);

    if(x >= marime && y >= marime)
    //cadranul stanga sus
        return 3*marime*marime +
               zParcurgere(x-marime, y-marime, marime);
}

int main()
{
    int x, y, n, k, marime = 1, i;
    f >> n >> k;

    for(i = 0; i < n; i++)
        marime = marime*2;

    for(i = 0; i < k; i++)
    {
        f >> x >> y;
        cout << zParcurgere(x-1, y-1, marime) << endl;
    }
    return 0;
}
