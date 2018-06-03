#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
ifstream f("date.in");

int n, i = 0;
char v[100];
int matrix[100][100];

int decodare(int litera)
{
    if(litera == 'w')
        return 0;
    if(litera == 'b')
        return 1;
}

int matrice(int x, int y, int marime)
{

    if(v[i] == 'i')
    {
        i++;
        marime = marime/2;
        matrice(x, y+marime, marime);
        matrice(x, y, marime);
        matrice(x+marime, y, marime);
        matrice(x+marime, y+marime, marime);
    }
    else
    {
        if(v[i] == 'i')
        {
            i += 5;
            matrix[x][y] = decodare(v[i+1]);
            matrix[x][y+1] = decodare(v[i+2]);
            matrix[x+1][y] = decodare(v[i+3]);
            matrix[x+1][y+1] = decodare(v[i+4]);
        }
        else if(v[i] == 'w')
        {
            i += 1;
            for(int j = x; j < x + marime; j++)
                for(int q = y; q < y + marime; q++)
                    matrix[j][q] = 0;
        }
        else if(v[i] == 'b')
        {
            i += 1;
            for(int j = x; j < x + marime; j++)
                for(int q = y; q < y + marime; q++)
                    matrix[j][q] = 1;
        }
    }
}

int main()
{

    f >> n;
    int iter = 0;
    while(f >> v[iter]) {
        iter++;
    }

    matrice(0, 0, n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
