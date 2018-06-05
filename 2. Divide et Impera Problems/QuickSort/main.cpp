#include <iostream>

using namespace std;

int v[100], n;

void quickSort(int left, int right)
{
    if(left < right)
    {
        int pivot = v[(left + right)/2];
        int i = left;
        int j = right;

        while (i <= j)
        {
            while(v[i] < pivot)
                i++;
            while(v[j] > pivot)
                j--;

            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }


        if(left < j)
            quickSort(left,i-1);
        if(i < right)
            quickSort(i+1,right);
    }
    return;
}



int main()
{


    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    quickSort(0,n-1);

    for(int i = 0; i < n; i++)
        cout << v[i] << " ";

    return 0;
}
