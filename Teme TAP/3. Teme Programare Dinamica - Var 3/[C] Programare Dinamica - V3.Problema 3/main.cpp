#include <iostream>
#include <fstream>
using namespace std;
ifstream f("date.in");

void citireMatrice(int &r, int &c, int m[100][100]) {
    f>>r>>c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            f>>m[i][j];
}

void afisareMatrice(int r, int c, int m[100][100]) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}

int minimul(int x, int y, int z){
    return min(min(x, y), z);
}

int main()
{
    int r,c;
    int m[100][100],aux[100][100];

    citireMatrice(r,c,m);
    afisareMatrice(r,c,m);
    cout<<endl;

    //construire matrice auxiliara care ne va ajuta sa
    //gasim submatricea maxima


    //la fiecare pas memoram valoarea maxima din noua
    //matrice + pozitia pe care se afla
    int maxim = 0, imaxim = 0, jmaxim = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            //marginea superiroara si din stanga la fel
            if(i == 0 || j == 0) {
                if(m[i][j] == 0)
                    aux[i][j] = 1;
                else
                    aux[i][j] = 0;

                //actualizare maxim
                if(aux[i][j] > maxim){
                    maxim = aux[i][j];
                    imaxim = i;
                    jmaxim = j;
                }
            }
            //acum cautam patratul
            else {
                if(m[i][j] == 0)
                    aux[i][j] = minimul(aux[i-1][j-1],
                                aux[i-1][j],aux[i][j-1]) + 1;
                else
                    aux[i][j] = 0;

                //actualizare maxim
                if(aux[i][j] > maxim){
                    maxim = aux[i][j];
                    imaxim = i;
                    jmaxim = j;
                }
            }
        }
    }

    afisareMatrice(r,c,aux);
    cout<<endl;
    cout<<maxim<<endl<<imaxim-maxim+1<<" "<<jmaxim-maxim+1<<endl;

    int k;
    f >> k;

    int nrPatrate = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(aux[i][j] >= k)
                nrPatrate = nrPatrate + aux[i][j] - k + 1;
        }
    }

    cout<<nrPatrate;

    return 0;
}
