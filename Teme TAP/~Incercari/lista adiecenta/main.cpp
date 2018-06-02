#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("date.in");

void postordine(int copil,int parinte, vector<int> v[], int marcat[])
{
    for(int i=0; i<v[copil].size(); i++)
        postordine(v[copil][i],copil,v,marcat);

    if(marcat[copil]==1) //daca e frunza
    {
        cout<<copil<<" ";
        marcat[parinte]=2;
    }
    else if(marcat[copil]==0)
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
            marcat[i]=1;

    postordine(1,0,v,marcat);

}
