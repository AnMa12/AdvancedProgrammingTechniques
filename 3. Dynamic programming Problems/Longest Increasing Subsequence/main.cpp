#include <iostream>

using namespace std;

int main()
{
/*
7
3 4 -1 0 6 2 3
*/

    int n;
    cin >> n;

    int v[n], subSeq[n];
    for(int i = 0; i < n; i++)
        cin >> v[i];

    //intializam toate poz cu 1
    //pt ca subMax e minim 1
    for(int i = 0; i < n; i++)
        subSeq[n] = 1;

    int i = 1, j = 0;
    while(i<=n) {
        while(i!=j) {
            cout<<endl<<"i = " << i << " j= "<<j<<endl;
            cout<<"*" << subSeq[0] <<"-" << subSeq[1] << "*" << endl;
            if(v[j] < v[i])
                subSeq[i] = subSeq[j] + 1;
            j++;
        }
        j = 0;
        i++;
    }

    for(int i = 0; i < n; i++)
        cout << subSeq[n] << " ";

    return 0;
}
