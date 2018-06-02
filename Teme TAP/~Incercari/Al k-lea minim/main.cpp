#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int pozRandom(int a, int b)
{
    srand(time(NULL));
    return rand()%(b-a + 1) + a;
}

int selKmin(int a[], int p, int u, int k)
{
    int m=pozRandom(p,u);
    if(m==k-1) return a[m];
    if(m<k-1) return selKmin(a,m+1,u,k);
    return selKmin(a,p,m-1,k);
}

int main()
{
    int k, n, v[100];
    cin>>n;
    for(int i=0; i < n; i++)
        cin>>v[i];

    cin>>k;

    cout<<selKmin(v,0,n-1,k);

    return 0;
}
