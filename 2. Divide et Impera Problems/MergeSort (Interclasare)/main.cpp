#include <iostream>
using namespace std;

void mergeSort(int v[], int left, int right) {

    if(left < right) {

        int mij = (right + left) / 2;
        mergeSort(v,left,mij);
        mergeSort(v,mij+1,right);

        int i1,i2,i;
        int aux[10];
        for( i1 = left, i2 = mij+1, i = left;
             i1 <= mij, i2 <= right;
             i++) {
            if(v[i1] <= v[i2])
                aux[i] = v[i1++];
            else
                aux[i] = v[i2++];
        }

        while(i1 <= mij)
            aux[i++] = v[i1++];

        while(i2 <= right)
            aux[i++] = v[i2++];

        for(int q = left; q <= right; q++)
            v[q] = aux[q];
    }
    return;
}

int main() {

    int v[100], n;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    mergeSort(v,0,n-1);

    for(int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}
