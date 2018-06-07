#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");

int M[100][100], pathM[100][100];
int n, m, sfin;

void afisM(int a[100][100])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int minim(int a, int b)
{
    if(a < b)
        return a;
    return b;
}

/*
3 3
2 5 4
3 2 1
4 5 10
Min cost: 18
The path: 2 3 2 1 10

3 4
1 3 5 8
4 2 1 7
4 3 2 3
Min cost: 12
The path: 1 3 2 1 2 3
*/

int main()
{
    f >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            f >> M[i][j];
    afisM(M);

    //starting point: M[0][0]
    pathM[0][0] = M[0][0];
    for(int j = 1; j < m; j++)
        pathM[0][j] = M[0][j] + pathM[0][j-1];
    for(int i = 1; i < n; i++)
        pathM[i][0] = M[i][0] + pathM[i-1][0];

    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            pathM[i][j] = M[i][j] + minim(pathM[i][j-1], pathM[i-1][j]);

    //afisM(pathM);
    cout << "Min cost: " << pathM[n-1][m-1] << endl;

    //--- find the path ---//
    int path[100];
    int ip = 0;
    int i = n-1, j = m-1;
    while(i >= 0 && j >= 0)
    {
        //cout<<"*"<<i<<"-"<<j<<"*  ";
        //cout << M[i][j] << endl;
        path[ip++] = M[i][j];
        if(pathM[i-1][j] == 0)
            j--;
        else if (pathM[i][j-1] == 0)
            i--;
        else
        {
            if(pathM[i-1][j] < pathM[i][j-1])
                i--;
            else
                j--;
        }
    }

    cout << "The path: ";
    for(int i = ip-1; i >= 0; i--)
        cout << path[i] << " ";

    return 0;
}
