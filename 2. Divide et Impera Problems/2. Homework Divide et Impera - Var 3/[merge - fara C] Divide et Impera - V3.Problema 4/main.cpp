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

//sortare dupa x
int cmpX(const void*a, const void*b)
{
    Punct *p1=(Punct*)a,*p2=(Punct*)b;
    return (p1->x-p2->x);
}

//sortare dupa y
int cmpY(const void* a,const void* b)
{
    Punct *p1=(Punct*)a,*p2=(Punct*)b;
    return (p1->y-p2->y);
}

long distanta(Punct p1, Punct p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x)
           + (p1.y-p2.y)*(p1.y-p2.y);
}

//daca sunt maxim 3 punctem rezolvam secvential
long cazMaxTreiPuncte(Punct P[],int n)
{
    long mini = 999999;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            if(distanta(P[i],P[j]) < mini)
                mini = distanta(P[i],P[j]);
    return mini;
}

//suboprogram pentru aflarea minimului dintre doua numere
long minim(long x, long y)
{
    if(x<y)
        return x;
    else
        return y;
}

long cmpMijloc(Punct fasie[], int marime, long d)
{
    //PAS IV: calculam dreapta de lungime minima formata din
    //extremitati din parti diferite
    long dPrim = d;
    qsort(fasie, marime, sizeof(Punct), cmpY);
    for (int  i = 0; i < marime; ++i)
        for (int j = i + 1; j < marime && (fasie[j].y - fasie[i].y) < dPrim; ++j)
            if (distanta(fasie[i], fasie[j]) < dPrim)
                dPrim = distanta(fasie[i], fasie[j]);
    return dPrim;
}

long celeMaiApropiateRecursiv(Punct P[], int n)
{
    //daca sunt 3 sau mai putine facem secvential
    if (n <= 3)
        return cazMaxTreiPuncte(P,n);
    //altfel se aplica metoda difide et impera
    Punct mijloc = P[n/2];

    //PAS III: impartim multimea de puncte recursiv in jumatati
    //pana gasim minimul de lungimi din fiecare jumatate
    float dl = celeMaiApropiateRecursiv(P, n/2);
    float dr = celeMaiApropiateRecursiv(P + n/2, n - n/2);
    float d = minim(dl,dr);
    Punct fasie[n];
    int j = 0;
    for (int i =0; i < n; i++)
        if ( (P[i].x - mijloc.x)<d)
            fasie[j]=P[i], j++;

    //PAS V: dupa ce gasim minimul de distante dintre cele dou parti.
    //trebuie sa vedem daca nu cumva sunt drepte mai scurte
    //cum extremitati in parti diferite
    return minim(d, cmpMijloc(fasie,j,d));
}

long celeMaiApropiate(Punct P[], int n)
{
    //PAS I: sortam initial punctele dupa x
    qsort(P, n, sizeof(Punct), cmpX);
    //PAS II: incepem sa le impartim in cate doua parti
    //sau sa facem secvential daca sunt mai putin sau 3
    return celeMaiApropiateRecursiv(P, n);
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

