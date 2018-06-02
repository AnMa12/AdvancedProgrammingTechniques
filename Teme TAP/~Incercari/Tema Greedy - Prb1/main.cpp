#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("date.in");
    int n;
    int v[100];

    f>>n; //trebuie sa fie par
    for(int i=0; i < n; i++)
        f>>v[i];

    cout<<"---------Pasi---------"<<endl;
    int S = 0, D = n-1;
    int j = 0, tura=0;
    int Sj1 = 0, Sj2= 0;
    //daca j=0 atunci e jucatorul 1, daca j=1 atunci e jucatorul 2
    while(S<=D)
    {
        if(tura%2==0) //jucatorul 1
        {
            if(v[S+1]+v[D]>=v[S]+v[D-1])
            {
                //alege din dreapta
                Sj1=Sj1+v[D];
                cout<<"La tura "<<tura+1<<", Jucatorul 1";
                cout<<" a ales DREAPTA cu valoarea "<<v[D];
                cout<<endl;
                D--;
                //cout<<"**"<<Sj1<<"**\n";
            }
            else
            {
                //alege din stanga
                Sj1=Sj1+v[S];
                cout<<"La tura "<<tura+1<<", Jucatorul 1";
                cout<<" a ales STANGA cu valoarea "<<v[S];
                cout<<endl;
                S++;
                //cout<<"**"<<Sj1<<"**\n";
            }
        }
        else //jucatorul 2
        {
            //jucatorul 2 alege random
            int alegere=0, nr=0;
            nr=rand()%100;
            srand(time(NULL));
            alegere=rand()%100+nr+tura;
            if(alegere%2==0)
            {
                //alege din stanga
                Sj2=Sj2+v[S];
                cout<<"La tura "<<tura+1<<", Jucatorul 2";
                cout<<" a ales STANGA cu valoarea "<<v[S];
                cout<<endl;
                S++;
                //cout<<"**"<<Sj2<<"**\n";
            }
            else
            {
                //alege din dreapta
                Sj2=Sj2+v[D];
                cout<<"La tura "<<tura+1<<", Jucatorul 2";
                cout<<" a ales DREAPTA cu valoarea "<<v[D];
                cout<<endl;
                D--;
                //cout<<"**"<<Sj2<<"**\n";
            }
        }
        tura++;
    }

    cout<<endl;
    cout<<"-------Punctaj-------"<<endl;
    cout<<"  Suma jucator 1: "<<Sj1<<endl;
    cout<<"  Suma jucator 2: "<<Sj2<<endl;

    if(Sj1>=Sj2)
        cout<<"--JUC 1 A CASTIGAT!--";
    else
        cout<<"--JUC 2 A CASTIGAT!--";

    return 0;
}
