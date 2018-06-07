#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;
ifstream f("date.in");

int k, n;

void afisV(int v[100])
{
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    f >> k;
    f >> n;
    int v[n];
    for(int i = 0; i < n; i++)
        f >> v[i];

    int auxv[n];
    for(int i = 0; i < n; i++)
        auxv[i] = 1;

    int i = 1, j = 0;
    while(i <= n) {
        j = 0;
        i ++;
        while(i != j){
            if(abs(v[i] - v[j]) >= k)
                auxv[i] = 1 + auxv[j];
            j++;
        }
    }

    int maxi = 0, nrMaxi = 0;
    for(int i = 0; i < n; i++) {
        if(auxv[i] > maxi) {
            maxi = auxv[i];
            nrMaxi = 1;
        }
        else if(auxv[i] == maxi) {
            nrMaxi++;
        }
    }

    afisV(auxv);

    cout << maxi << endl;
    cout << nrMaxi << endl;
}
