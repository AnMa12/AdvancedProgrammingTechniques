#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("date.in");

void postordine(int copil,int parinte, vector<int> v[], int marcat[])
{
    for(int i=0; i<v[copil].size(); i++)
        postordine(v[copil][i],copil,v,marcat); //mergem cat mai la stanga

    if(marcat[copil]==1) //daca e frunza
    {
        cout<<copil<<" "; //e bun deci afisam
        marcat[parinte]=2; //marcam parintele pt ca el va fi adiacent
    }
    else if(marcat[copil]==0) //daca nu e marcat e neadiacent
        cout<<copil<<" ";
}

int main()
{
    vector<int> v[100];
    int n,a,b;
    f>>n;
    while(f>>a>>b)
        v[a].push_back(b);

    int radacina=1;

    int marcat[100];
    for(int i = 1; i <= n; i++)
        marcat[i]=0;

    for(int i = 1; i <= n; i++)
        if(v[i].size()==0 && i!=radacina)
            marcat[i]=1; //marcam frunzele

    postordine(1,0,v,marcat);

}
