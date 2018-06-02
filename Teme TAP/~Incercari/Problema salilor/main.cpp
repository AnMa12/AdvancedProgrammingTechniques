#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream f("date.in");

struct intervale
{
    int ora_inc,
        ora_fin,
        nr_activitate;
};

struct sali
{
    intervale sala[100];
    int nr_activ_sala=0;
};

bool comp(intervale I1, intervale I2)
{
    return I1.ora_inc < I2.ora_inc;
}

int main()
{
    int n;
    intervale I[100];

    f>>n;
    for(int i = 0; i < n; i++)
    {
        f>>I[i].ora_inc>>I[i].ora_fin;
        I[i].nr_activitate=i+1;
    }

    sort(I, I + n, comp);

    for(int i = 0; i < n; i++)
        cout<<I[i].nr_activitate<<endl;

    int nr_sali=0;
    sali S[100];
    //planificam primul eveniment in prima sala
    S[0].sala[0].nr_activitate=I[0].nr_activitate;
    S[0].sala[0].ora_inc=I[0].ora_inc;
    S[0].sala[0].ora_fin=I[0].ora_fin;

    for(int i = 1; i < n; i++)
    {
        //parcurgem salile
        int ok=0;
        for(int j = 0; j <= nr_sali && ok == 0; j++)
        {
            if(S[j].sala[S[j].nr_activ_sala].ora_inc < I[i].ora_inc &&
                    S[j].sala[S[j].nr_activ_sala].ora_inc < I[i].ora_fin &&
                    S[j].sala[S[j].nr_activ_sala].ora_fin <= I[i].ora_inc &&
                    S[j].sala[S[j].nr_activ_sala].ora_fin < I[i].ora_fin )
                //adaugam noua activitate in sala respectiva
            {
                ok=1;
                S[j].nr_activ_sala++; //crestem numarul de activ din sala aia
                S[j].sala[S[j].nr_activ_sala].nr_activitate=I[i].nr_activitate;
                S[j].sala[S[j].nr_activ_sala].ora_inc=I[i].ora_inc;
                S[j].sala[S[j].nr_activ_sala].ora_fin=I[i].ora_fin;
            }
        }
        if(ok==0)
        {
            //facem o alta sala
            nr_sali++;
            S[nr_sali].sala[S[nr_sali].nr_activ_sala].nr_activitate=I[i].nr_activitate;
            S[nr_sali].sala[S[nr_sali].nr_activ_sala].ora_inc=I[i].ora_inc;
            S[nr_sali].sala[S[nr_sali].nr_activ_sala].ora_fin=I[i].ora_fin;
        }
    }

    cout<<"Nr min sali necesare: "<<nr_sali+1;
    cout<<endl;
    for(int i = 0; i <= nr_sali; i++)
    {
        cout<<"Sala "<<i+1<<": ";
        for(int j = 0; j <= S[i].nr_activ_sala; j++)
            cout<<S[i].sala[j].nr_activitate<<"  ";
        cout<<endl;
    }

    return 0;
}
