#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
using namespace std;
ifstream f("date.in");
int n, x;
void divide(int n, int dim, int x, int y) {

    if(dim = 1) {
        cout << x+1 << " " << y+1 << endl;
    }
    else {
        dim = dim/4;
        cout<< "**" << n << "*" << dim << "**"<< endl;
        if(n <= dim) {
            //triunghiul din stanga sus
            cout<<"a"<<endl;
            divide(n, dim, x, y);
        }

        else if(n <= dim*2) {
            cout<<"b"<<endl;
            //triunghiul din dreapta jos
            divide(n, dim, x + dim/2, y + dim/2);
        }

        else if(n <= dim*3) {
            cout<<"c"<<endl;
            //triunghiul din dreapta sus
            divide(n, dim, x, y + dim/2);
        }

        else if(n <= dim*4) {
            cout<<"d"<<endl;
            //triunghiul din stanga jos
            divide(n, dim, x + dim/2, y);
        }

    }
}
int main()
{
    f >> n >> x;
    int dim = pow(2,n) * pow(2,n);
    divide(x, dim, 0, 0);
}
