#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream f("date.in");

void merge(vector<int> &v, int stg, int mij, int drpt)
{
    int i = stg, j = mij;
    vector<int> aux;
    while (i < mij && j <= drpt)
    {
        if(v[i] > v[j])
            aux.push_back(v[j++]);
        else
            aux.push_back(v[i++]);
    }
    while (i < mij)
        aux.push_back(v[i++]);
    while (j <= drpt)
        aux.push_back(v[j++]);

    copy(aux.begin(), aux.end(), v.begin()+stg);
}
int inv_count = 0;
int inversiuni(vector<int> &v, int stg, int mij, int drpt)
{
    int i = stg, j = mij;
    while (i < mij && j <= drpt)
    {
        if(v[i] > 2*v[j])
        {
            inv_count = inv_count + (mij - i);
            j++;
        }
        else
            i++;
    }

    return inv_count;
}
int divide(vector<int> &v, int stg, int drpt)
{
    int nrInv;
    if(stg < drpt)
    {
        divide(v, stg, (stg+drpt)/2);
        divide(v, (stg+drpt)/2+1, drpt);
        nrInv= inversiuni(v, stg, (stg+drpt)/2+1, drpt);
        merge(v, stg, (stg+drpt)/2+1, drpt);
    }
    return nrInv;
}

int main()
{
    int n, x;
    f >> n;
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        f >> x;
        v.push_back(x);
    }

    cout<<divide(v,0,n-1);

    return 0;
}
