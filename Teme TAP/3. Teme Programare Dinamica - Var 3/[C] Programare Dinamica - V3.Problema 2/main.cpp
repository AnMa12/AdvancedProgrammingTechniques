#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
ifstream f("date.in");

void citireMatrice(int &r, int &c, int m[100][100]) {
    f>>r>>c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            f>>m[i][j];
}

void afisareMatrice(int r, int c, int m[100][100]) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}

int maximul(int x, int y, int z){
    return max(max(x, y), z);
}

int main()
{
    /* initialize random seed: */
    srand (time(NULL));

    int r, c, maxim = 0;
    int m[100][100], aux[100][100];

    citireMatrice(r,c,m);
    //afisareMatrice(r,c,m);
    //cout<<endl;

    //generare random numar de la 0 la r-1
    int randomRow = rand() % r; //first element is m[randomRow][0];
    cout<<"S-a inceput de pe pozitia: "<<randomRow<<" 0"<<endl;

    //CONSTRUIRE MATRICE AUXILIARA
    aux[randomRow][0] = m[randomRow][0];
    for(int j = 1; j < c; j++)
    {
        maxim = 0;
        //gasire maxim pe coloana anterioara care poate sa fie atins!!!
        for(int i = 0; i < r; i++)
        {
            //daca are NE E SE
            if(i > 0 && i < r-1)
                maxim = maximul(aux[i-1][j-1],aux[i][j-1],aux[i+1][j-1]);
                //cout<<"1  "<<maxim<<endl;}

            //daca are E si SE
            else if(i < r-1)
                maxim = max(aux[i][j-1],aux[i+1][j-1]);
                //cout<<"2  "<<maxim<<endl;}

            //daca are NE si E
            else if(i > 0)
                maxim = max(aux[i-1][j-1],aux[i][j-1]);
                //cout<<"3  "<<maxim<<endl;}

                aux[i][j] = maxim + m[i][j];
        }
    }

    //PENTRU GASIRE SUMA MAXIMA CAUTAM MAXIMUL DE PE ULTIMA COLOANA
    int sumaMaxima = 0, imax = 0, jmax = 0;
    maxim = 0;
    for(int i = 0; i < r; i++)
        if(aux[i][c-1] > maxim)
        {
            maxim = aux[i][c-1];
            imax = i;
            jmax = c-1;
        }

    sumaMaxima = maxim;
    cout<<sumaMaxima<<endl;
    cout<<imax<<" "<<jmax<<endl;

    //CALCULARE URMATORUL ELEMENT CARE TREBUIE CAUTAT
    int element = 0;
    element = maxim - m[imax][jmax];

    //PARCURGERE INVERSA PE COLOANE A MATRICEI AUXILIARE ASTFEL INCAT SA GASIM DRUMUL
    int ok = 0, counter = 0;
    for(int j = c-2; j >= 0; j--)
    {
        //gasim elementul cautat pe fiecare linie
        maxim = 0;
        counter = 0;
        for(int i = 0; i < r; i++)
            //daca elementul apare de mai multe ori => traseu neunic
            if(aux[i][j] == element)
            {
                counter++;
                maxim = aux[i][j];
                imax = i;
                jmax = j;
            }
        cout<<imax<<" "<<jmax<<endl;
        element = maxim - m[imax][jmax];

        if(counter > 1)
            ok = 1;
    }

    if(ok == 0)
        cout<<"Traseul este unic";
    else
        cout<<"Traseul nu este unic";

    //cout<<endl;
    //afisareMatrice(r,c,aux);
    return 0;
}
