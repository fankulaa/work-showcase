#include<cmath>
#include<iomanip>
#include<fstream>
#include<iostream>

using namespace std;

struct Zmogus
{
    string vardas,pavarde;
    int h,m,s,h1,m1,s1;
    int uzt;
};

void Yrasimas(Zmogus &zmogus)
{
    cin>>zmogus.vardas;
    cin>>zmogus.pavarde;
    cin>>zmogus.h;
    cin>>zmogus.m;
    cin>>zmogus.s;
    cin>>zmogus.h1;
    cin>>zmogus.m1;
    cin>>zmogus.s1;
}

int kiek_Uztruko(int h,int m,int s,int h1,int m1,int s1)
{
    int uzt=h1*3600+m1*60+s1-h*3600-m*60-s;
    return uzt;
}

void SpeedTest(int &fasti,int &slowi,int i,int &fast,int &slow,int time) //pilnai nesuprantu kas cia per dalykas
{
    if(time<fast)
    {
        fast=time;
        fasti=i;
    }
    if(time>slow)
    {
        slow=time;
        slowi=i;
    }
}

int main ()
{
    int n, fasti, slowi=0,fast=0,slow;
    cin>>n;
    Zmogus  zmones[n];
    for(int i=0;i<n;i++)
    {
        Yrasimas(zmones[i]);
        zmones[i].uzt=kiek_Uztruko(zmones[i].h,zmones[i].m,zmones[i].s,zmones[i].h1,zmones[i].m1,zmones[i].s1);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(zmones[i].uzt>zmones[j].uzt){
                swap(zmones[i],zmones[j]);
            }
        }
    }

/*
test with:
8
j j 1 0 0 2 0 0
z z 1 0 1 2 3 4
s s 3 2 1 4 2 1
w w 1 2 3 4 5 6
e e 5 4 4 6 5 5
t t 1 1 1 7 7 7
y y 1 1 1 1 1 1
g g 1 1 1 1 2 1
*/

    cout<<"greiciausias: "<<zmones[0].vardas<<" "<<zmones[0].pavarde<<" truko:"<<zmones[0].uzt<<" sekundes"<<endl;
    cout<<"leciausas: "<<zmones[n-1].vardas<<" "<<zmones[n-1].pavarde<<" truko:"<<zmones[n-1].uzt<<" sekundes "<<endl;
    return 0;
}

