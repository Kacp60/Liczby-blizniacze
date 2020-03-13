//Kacper Walkusz kl.Ibg VLO
#include <iostream>
#include <fstream>
#include <cmath>
#define N 1000000

using namespace std;

bool tab[N];

void Eratostenes()
{
    tab[0]=1;
    tab[1]=1;
    for(int i=2; i<=sqrt(N); i++)
    {
        if(tab[i]==0)
            for(int j=i+i; j<N; j=j+i)
            {
                tab[j]=1;
            }
    }
}

int main()
{
    int tab1[78498];
    int j = 0;
    long long sum=0, suma = 0;
    fstream dane1;
    fstream liczby1;
    Eratostenes();

    dane1.open("dane1.txt", ios :: out);

    for(int i=2; i<N; i++)
    {
        if(tab[i]==0)
        {
            dane1<<i<<endl;
        }
    }

    dane1.close();

    dane1.open("dane1.txt", ios :: in);

    for(int i=0; i<78498; i++)
    {
        dane1>>tab1[i];
    }

    dane1.close();

    liczby1.open("liczby1.txt", ios :: out);

    for(int i = 1; i<78497; i++)
    {
        if(tab1[i]-tab1[j]==2)
        {
            liczby1<<tab1[j]<<" "<<tab1[i]<<endl;
            suma=suma+1;
        }
        j++;
    }

    liczby1<<suma;

    liczby1.close();


    return 0;
}
