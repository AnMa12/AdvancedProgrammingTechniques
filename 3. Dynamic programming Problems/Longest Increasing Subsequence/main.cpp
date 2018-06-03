#include <iostream>
#include <algorithm>

using namespace std;

/*Input data example:
7
3 4 -1 0 6 2 3
R: -1 0 2 3 => 4*/

int main()
{


    int n;
    cin >> n;

    int v[n], subSeq[n];
    for(int i = 0; i < n; i++)
        cin >> v[i];

    //intializam toate poz cu 1
    //pt ca subMax e minim 1
    for(int i = 0; i < n; i++)
        subSeq[i] = 1;

    int i = 1, j = 0;
    while(i<=n) {
        while(i!=j) {
            if(v[j] < v[i])
                subSeq[i] = subSeq[j] + 1;
            j++;
        }
        j = 0;
        i++;
    }

    int maxi = 0;
    for(int i = 0; i < n; i++)
        if(subSeq[i] > maxi)
            maxi = subSeq[i];

    cout << maxi;

    return 0;
}
