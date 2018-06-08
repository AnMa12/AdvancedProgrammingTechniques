#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
using namespace std;
ifstream f("date.in");
int n, x, dim;
void divide(int n, int x, int y, int index) {

    if(dim == 1) {
        cout << x + 1 << " " << y+1 << endl;
    }
    else {
        dim = dim/4;
        int halfDim = 0;
        if(dim > 2)
            halfDim = dim/2;
        else
            halfDim = 1;

        if(n <= index + dim) {
            //triunghiul din stanga sus
            cout<<"a"<<endl;
            divide(n, x, y, 0*dim);
        }
        else if(n <= index + dim*2) {
            cout<<"b"<<endl;
            //triunghiul din dreapta jos
            divide(n, x + halfDim, y + halfDim, 1*dim);
        }
        else if(n <= index + dim*3) {
            cout<<"c"<<endl;
            //triunghiul din dreapta sus
            divide(n, x, y + halfDim, 2*dim);
        }
        else if(n <= index + dim*4) {
            cout<<"d"<<endl;
            //triunghiul din stanga jos
            divide(n, x + halfDim, y, 3*dim);
        }

    }
}
int main()
{
    f >> n >> x;
    dim = pow(2,n) * pow(2,n);
    divide(x, 0, 0, 0);
}
