#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");
int v[100],n,nr;
int caut(int i, int j)
{
    //conditia de varf: termenu din dreapta
    //vf-ului sa fie mai mic si cel din stanga mai mic

    //incepem sa cautam varful de pe mijloc
    //daca am gasit varful
    if(v[(i+j)/2] > v[(i+j)/2]+1 && v[(i+j)/2] > v[(i+j)/2]-1)
    {
        //am gasit varful
        return v[(i+j)/2];
    }
}
main ( )
{
    f>>n;
    for (int i=1; i<=n; i++)
        f>>v[i];
    cout<<caut(1,n);
}
