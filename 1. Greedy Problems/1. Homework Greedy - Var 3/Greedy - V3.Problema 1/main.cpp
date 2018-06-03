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

    int SP=0, SIP=0;
    f>>n; //trebuie sa fie par
    for(int i=1; i <= n; i++)
    {
        f>>v[i];
        if(i%2==0)
            SP=SP+v[i];
        else
            SIP=SIP+v[i];
    }

    cout<<"---------Pasi---------"<<endl;
    int S = 1, D = n;
    int tura=0;
    int Sj1 = 0, Sj2= 0;

    while(S<=D)
    {
        if(tura%2==0) //jucatorul 1
        {
            if(SP>=SIP) //daca suma para e mai mare decat impara
            {
                //alegem pozitia para
                if(S%2==0)
                {
                    //stanga e para
                    Sj1=Sj1+v[S]; //crestem suma jucatorului
                    cout<<"La tura "<<tura+1<<", Jucatorul 1";
                    cout<<" a ales STANGA cu valoarea "<<v[S];
                    cout<<endl;
                    SP=SP-v[S]; //scadem suma para
                    S++; //ne deplasam la dreapta
                }
                else if(D%2==0)
                {
                    //dreapta e para
                    Sj1=Sj1+v[D]; //crestem suma jucatorului
                    cout<<"La tura "<<tura+1<<", Jucatorul 2";
                    cout<<" a ales DREAPTA cu valoarea "<<v[D];
                    cout<<endl;
                    SP=SP-v[D]; //scadem suma para
                    D--; //ne deplasam la stanga
                }
            }
            else //daca suma impara e mai mare decat aia para
            {
                //alegem pozitia impara
                if(S%2!=0)
                {
                    //alegem stanga
                    Sj1=Sj1+v[S]; //crestem suma jucatorului
                    cout<<"La tura "<<tura+1<<", Jucatorul 1";
                    cout<<" a ales STANGA cu valoarea "<<v[D];
                    cout<<endl;
                    SIP=SIP-v[S]; //scadem suma impara
                    S++; //ne deplasam la dreapta
                }
                else if(D%2!=0)
                {
                    //alegem dreapta
                    Sj1=Sj1+v[D]; //crestem suma jucatorului
                    cout<<"La tura "<<tura+1<<", Jucatorul 2";
                    cout<<" a ales DREAPTA cu valoarea "<<v[D];
                    cout<<endl;
                    SIP=SIP-v[D]; //scadem suma impara
                    D--; //ne deplasam la stanga
                }
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
                SIP=SIP-v[S];
                S++;
            }
            else
            {
                //alege din dreapta
                Sj2=Sj2+v[D];
                cout<<"La tura "<<tura+1<<", Jucatorul 2";
                cout<<" a ales DREAPTA cu valoarea "<<v[D];
                cout<<endl;
                if(D%2==0) SP=SP-v[D];
                else SIP=SIP-v[D];
                D--;
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
