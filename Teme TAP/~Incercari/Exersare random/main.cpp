#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
    int ok=5;
    while(ok!=0)
    {
        int alegere=0, nr=0;
            nr=rand()%100;
            srand(time(NULL));
            alegere=rand()%100+nr+ok;
            cout<<alegere<<endl;
            ok--;
    }

    cout << "Hello world!" << endl;
    return 0;
}
