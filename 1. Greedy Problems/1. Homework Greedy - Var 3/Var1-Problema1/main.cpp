#include <iostream>

using namespace std;

int n, v[100];

int indiceValoare(int s, int n)
{
    if (n >= s) {
         int mij = (s + n) / 2;
        cout<< " " << mij << " ";
        cout<<v[mij]<<endl;
        if(v[mij] == mij)
        return mij;
        else if(v[mij] < mij)
            return indiceValoare(s,mij-1);
        else
            return indiceValoare(mij+1,n);
    }


    return -1;
}


int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    cout << indiceValoare(0,n-1);

    return 0;
}
