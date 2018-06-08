#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ifstream f("date.in");

int n, nr, dim;

divide(int x, int y, int way)
{
    if(dim == 1) {
        cout << x+1 << " " << y+1;
    }
    else {
        dim = dim/4;
        int halfDim;
        if(dim > 2)
            halfDim = dim/2;
        else
            halfDim = 1;

        if(nr <= dim + way) {
            //triunghi stanga sus
            divide(x,y,0);
        }
        else if(nr <= 2*dim + way) {
            //triunghi dreapta jos
            divide(x + halfDim, y + halfDim, dim);
        }
        else if(nr <= 3*dim + way) {
            //triunghi in dreapta sus
            divide(x, y + halfDim, 2*dim);
        }
        else if(nr <= 4*dim + way) {
            divide(x + halfDim, y, 3*dim);
        }
    }
}

int main () {

    f >> n >> nr;
    dim = pow(2,n) * pow(2,n);
    divide(0, 0, 0);

}
