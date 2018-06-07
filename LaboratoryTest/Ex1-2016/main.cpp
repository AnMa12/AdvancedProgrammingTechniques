#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");

int M[100][100], pathM[100][100];
int n, m, sfin;

int maxim(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

void afisM(int a[100][100])
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    f >> n >> m >> sfin;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            f >> M[i][j];
    //afisM(M);

    for(int i = 1; i <= n; i++)
        for(int j = m; j >= 1; j--)
        {
            if(i == 1 && j == m)
                pathM[i][j] = M[i][j];
            else if(M[i-1][j] == 0)
                pathM[i][j] = M[i][j] + pathM[i][j+1];
            else if(M[i][j+1] == 0)
                pathM[i][j] = M[i][j] + pathM[i-1][j];
            else
                pathM[i][j] = M[i][j] + maxim(pathM[i][j+1], pathM[i-1][j]);
        }
    //afisM(pathM);

    int i = n, j = 1;
    int path[100], ip = 0;
    while( i >= 0 && j >= 0)
    {
        path[ip++] = M[i][j];
        if(pathM[i][j+1] == 0)
            i--;
        else if(pathM[i-1][j] == 0)
            j++;
        else if(pathM[i][j+1] > pathM[i-1][j])
            j++;
        else
            i--;
    }

    int smin = 0;
    int sparcurs = 0;
    for(int i = ip-2; i >= 0; i--)
    {
        sparcurs = sparcurs + path[i];
        if(sparcurs < smin)
            smin = sparcurs;
    }

    //smin cost este valoarea de pe parcurs
    //care are nevoie de cele mai multe resurse
    smin = (-1) * smin + 1;

    sparcurs = smin;
    for(int i = ip-2; i >= 0; i--)
        sparcurs = sparcurs + path[i];

    if(sparcurs > sfin)
        cout << smin << endl;
    else
        cout << smin + sfin - sparcurs <<endl;

    for(int i = ip-2; i >= 0; i--)
    {
        cout << path[i] << " ";
    }

    return 0;
}
