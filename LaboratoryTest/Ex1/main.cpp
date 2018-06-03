#include<iostream>
#include<fstream>

using namespace std;
ifstream f("date.in");

int n, i = 0;
char v[100];
int matrix[100][100];

int decodare(int litera) {
    if(litera == 'w')
        return 0;
    if(litera == 'b')
        return 1;
}

int matrice(int x, int y, int marime) {

    if(marime == 2) {
        if(v[i] == 'i') {
                cout<<endl; cout<<"1";
           matrix[x][y] = decodare(v[i+1]);
           matrix[x][y+1] = decodare(v[i+2]);
           matrix[x+1][y] = decodare(v[i+3]);
           matrix[x+1][y+1] = decodare(v[i+4]);
            for(int j = i; j < i+5; j++)
                cout<<v[j]<< "-";
           i += 5;
        } else if(v[i] == 'w') {
            cout<<endl;
            cout<<"2";
           matrix[x][y] = 0;
           matrix[x][y+1] = 0;
           matrix[x+1][y] = 0;
           matrix[x+1][y+1] = 0;
           cout<<v[i]<<"*";
           i += 1;
        } else if(v[i] == 'b') {
            cout<<endl; cout<<"3";
           matrix[x][y] = 1;
           matrix[x][y+1] = 1;
           matrix[x+1][y] = 1;
           matrix[x+1][y+1] = 1;
           cout<<v[i]<<"~";
           i += 1;
        }
    }
    else if(v[i] == 'i') {

        cout<<endl<<endl;
        cout<<v[i]<<"...";

        i++;

        marime = marime/2;
        matrice(x, y+marime, marime);
        matrice(x, y, marime);
        matrice(x+marime, y, marime);
        matrice(x+marime, y+marime, marime);
    }
}

int main() {

    cin >> n;
    for(int i = 0; i < 30; i++)
        cin >> v[i];

    matrice(0, 0, n);

    cout<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
