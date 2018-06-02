#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream f("date.in");

struct Punct
{
    int x, y;
};

long distanta(Punct p1, Punct p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)
           + (p1.y-p2.y)*(p1.y-p2.y);
}

int cmpX(const void*a, const void*b)
{
    Punct *p1=(Punct*)a,*p2=(Punct*)b;
    return (p1->x-p2->x);
}

long minim(long x, long y)
{
    if(x<y)
        return x;
    else
        return y;
}

void interclaseaza(Punct Py[], int stg, int mij, int drpt)
{
    int i1 = stg, i2 = mij+1, j1 = mij, j2 = drpt, auxi = 0;
    Punct Paux[drpt+1];

    for(int i = 0; i <= drpt; i++)
            cout<<"*~~afis Py inainte de interclasare~~* "<<Py[i].x<<"-"<<Py[i].y<<endl;
            cout<<endl;

    while( i1 < j1 && i2 < j2 )
    {
        if(Py[i1].y > Py[i2].y)
        {
            Paux[auxi++]=Py[i2];
            i2++;
        }
        else
        {
            Paux[auxi++]=Py[i1];
            i1++;
        }
    }
    while( i1 <= j1)
    {
        Paux[auxi++]=Py[i1];
        i1++;
    }
    while ( i2 <= j2)
    {
        Paux[auxi++]=Py[i2];
        i2++;
    }

    for(int i = 0; i <= drpt; i++)
            cout<<"*~~afis Paux~~* "<<Paux[i].x<<"-"<<Paux[i].y<<endl;
            cout<<endl;

    //copiem Paux peste Py
    for(int i = 0; i <= drpt; i++)
        Py[i] = Paux[i];


}

long celeMaiApropiateRecursiv(Punct Px[], Punct Py[], int stg, int drpt)
{
    if( (drpt-stg+1) > 2 )
    {
        int mij = (stg + drpt)/2;
        long dstg = celeMaiApropiateRecursiv(Px, Py, stg, mij);
        long ddrpt = celeMaiApropiateRecursiv(Px, Py, mij+1, drpt);
        long d = minim(dstg,ddrpt);

        for(int i = 0; i <= drpt; i++)
            cout<<"*afis Py inainte de interclasare* "<<Py[i].x<<"-"<<Py[i].y<<endl;
            cout<<endl;

        interclaseaza(Py, stg, mij, drpt);

        //test afisare
        for(int i = 0; i <= drpt; i++)
            cout<<"*afis Py interclasat* "<<Py[i].x<<"-"<<Py[i].y<<endl;
            cout<<endl;

        Punct Pfasie[drpt+1];
        int indice = 0;
        for(int i = stg; i <= drpt; i++)
            if((Py[i].x >= (Px[mij].x-sqrt(d))) && (Py[i].x <= (Px[mij].x+sqrt(d))))
                Pfasie[indice++]=Py[i];

        //test afisare
        for(int i = 0; i < indice; i++)
            cout<<"*afis Pfasie* "<<Pfasie[i].x<<"-"<<Pfasie[i].y<<endl;
            cout<<endl;

        for(int i = 0; i< indice; i++)
            for( int j = i+1; j < i+7 && j < indice; j++)
                if(distanta(Pfasie[i],Pfasie[j])<d)
                    d = distanta(Pfasie[i], Pfasie[j]);

        //test pt distante
        cout<<"&&&"<<d<<"&&&"<<endl;
        return d;
    }
    else
    {
        int aux;
        if(Py[stg].y > Py[stg+1].y)
        {
            aux = Py[stg].y;
            Py[stg].y = Py[stg+1].y;
            Py[stg+1].y = aux;

            aux = Py[stg].x;
            Py[stg].x = Py[stg+1].x;
            Py[stg+1].x = aux;

            //test pt distante
            cout<<"& &"<<distanta(Py[stg],Py[stg+1])<<"& &"<<endl;
            return distanta(Py[stg],Py[stg+1]);
        }

        if(Py[drpt].y > Py[drpt+1].y)
        {
            aux = Py[drpt].y;
            Py[drpt].y = Py[drpt+1].y;
            Py[drpt+1].y = aux;

            aux = Py[drpt].x;
            Py[drpt].x = Py[drpt+1].x;
            Py[drpt+1].x = aux;

            //test pt distante
            cout<<"&*&"<<distanta(Py[drpt],Py[drpt+1])<<"&*&"<<endl;
            return distanta(Py[drpt],Py[drpt+1]);
        }

    }

}

long celeMaiApropiate(Punct Px[], int n)
{
    //PAS I: sortam initial punctele dupa x
    qsort(Px, n, sizeof(Punct), cmpX);
    //PAS II: realizam un vector Y care sa fie copie
    Punct Py[n];
    for(int i = 0; i < n; i++)
        Py[i] = Px[i];

    //test afisare
    for(int i = 0; i < n; i++)
        cout<<"*afis Y* "<<Py[i].x<<"-"<<Py[i].y<<endl;

    //PAS III: incepem sa impartim problema in subprobleme
    return celeMaiApropiateRecursiv(Px, Py, 0, n-1);
}

int main()
{
    int n;
    f >> n;
    Punct P[n];

    for(int i = 0; i < n; i++)
        f >> P[i].x >> P[i].y;

    cout<<"Cea mai mica distanta este: "<<sqrt(celeMaiApropiate(P,n));
    return 0;
}

