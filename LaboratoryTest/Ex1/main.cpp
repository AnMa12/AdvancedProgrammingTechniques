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


/* observatie:
   conditia de oprire nu este marime == 2
   pentru ca sunt urmatoarele cazuri:
   8 ibwbw unde marimea nu ajunge la 2, oprindu-ne cand marimea ajunge la 4
   sau in cazul 8 b, unde ne oprim cand marimea e chiar la 8
   -----
   cheia sta in numarul de i-uri
   oprirea o gasim in fuctie de cate i-uri sunt la inceptului programului
   -----
   2  = 2^1 oprirea se poate face cand suntem la marimea de 2
   4  = 2^2
   8  = 2^3
   16 = 2^4
*/

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
