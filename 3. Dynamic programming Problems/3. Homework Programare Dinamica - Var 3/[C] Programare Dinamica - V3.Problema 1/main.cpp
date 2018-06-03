#include <iostream>
#include<fstream>
#include <string.h>
using namespace std;

ifstream f("date.in");

int main()
{
    char cuv[100][100], prop[100], *p;
    string str;
    getline(f,str);

    for ( int i = 0 ; i < str.length(); i++)
        prop[i] = str[i];

    int n = 0;
    p = strtok(prop, " ");
    while(p != NULL)
    {
        strcpy(cuv[n++], p);
        p=strtok(NULL, " ");
    }

    //afisare test a matricei de cuvinte
    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < strlen(cuv[i]); j++)
            cout<<cuv[i][j];
        cout<<endl;
    }*/

    //construire matrice auxiliara + vectori auxiliari
    int t[150], l[150], aux[150][150];
    //mergem de la coada la cap
    //primele doua cuvinte din ultimul cuvant
    //in matricea aux le punem pozitia cuvantului din care fac parte
    aux[int(cuv[n-1][0])][int(cuv[n-1][1])] = n-1;
    t[n-1] = n;
    l[n-1] = 1;

    for(int i = n-2; i >= 0; i--)
    {
        //luam urmatorul cuvant si cautam sa vedem daca
        //ultimele doua literele ale lui apar in inceptul altui
        //cuvant, folosind matricea aux - cautare O(1)
        int inceput = aux[int(cuv[i][strlen(cuv[i])-2])][int(cuv[i][strlen(cuv[i])-1])];
        if( inceput != 0)
        {
            t[i] = inceput;
            l[i] = 1 + l[inceput];
        }
        else
        {
            t[i] = n;
            l[i] = 1;
        }

        //continuarea lui aux cu sfarsitul noului cuvant
        int sfarsit =  aux[int(cuv[i][0])][int(cuv[i][1])];
        if( sfarsit != 0 && l[sfarsit] < l[i])
            aux[int(cuv[i][0])][int(cuv[i][1])] = i;
        else if ( sfarsit == 0)
            aux[int(cuv[i][0])][int(cuv[i][1])] = i;
    }
    //done matrice aux

    /*for(int i = 0; i < n; i++)
        cout << t[i] << " ";
    cout<<endl;

    for(int i = 0; i < n; i++)
        cout << l[i] << " ";
    cout<<endl;*/

    int maxim = 0, imax = 0;
    for(int i = 0; i < n; i++)
        if(l[i] > maxim)
        {
            maxim = l[i];
            imax = i;
        }
    while(imax < n)
    {
        cout << cuv[imax] << endl;
        imax = t[imax];
    }

    return 0;
}
