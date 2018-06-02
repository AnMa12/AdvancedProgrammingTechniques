#include <string.h>
#include <iostream>
using namespace std;

int palindrom(char *cuv)
{
    int n = strlen(cuv);

    int T[n];
    bool P[n][n];
    int nrPalindrom = 0;

    int i, j, k, L;

    //palindroamele de un caracter
    for (i = 0; i < n; i++)
    {
        P[i][i] = true;
        nrPalindrom++;
    }

    //palindroamele de 2 sau mai multe caractere
    for (L = 2; L <= n; L++)
    {
        //de unde pot incepe
        for (i = 0; i < n-L+1; i++)
        {
            //unde se termina daca incep pe i
            j = i + L - 1;

            if (L == 2)
                if(cuv[i] == cuv[j])
                    P[i][j] = true;
                else
                    P[i][j] = false;
            else
                if((cuv[i] == cuv[j]) && P[i+1][j-1])
                    P[i][j] = true;
                else
                    P[i][j] = false;

            if(P[i][j] == true)
                nrPalindrom++;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (P[0][i] == true)
            T[i] = 0;
        else
        {
            T[i] = 99999;
            for(j = 0; j < i; j++)
            {
                if(P[j+1][i] == true && 1 + T[j] < T[i])
                    T[i] = 1 + T[j];
            }
        }
    }
    cout << "Cuvantul " << cuv << " contine: " << nrPalindrom << " palindroame" << endl;

    return T[n-1] + 1;
}

int main()
{
   char cuv[] = "abcbaabc";
   cout << "si se poate imparti in: " << palindrom(cuv) << " palindroame.";
   return 0;
}
