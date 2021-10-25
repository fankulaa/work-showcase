#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
int nk_test(int n,int k) // Patikrinimas salygos(2<n<30) bei (2<k<7)
{
    if (n<2 || n>30){ //mokiniai
        cout <<"Mokiniu yra per daug arba per mazai, bandykite is naujo"<< endl;
        return 0;
    }

    if (k<2 || k>7){ //uzduotys
        cout << "k: "<<k <<endl;
        cout <<"Uzduociu yra per daug arba per mazai, bandykite is naujo"<< endl;

        return 0;
    }
}
int irasymas()
{

}
int main()
{

    int n=0, k=0;
    cin >> n>>k;
    nk_test(n,k); // Patikrinimas salygos(2<n<30) bei (2<k<7)


    //variables
    double dalis[k];
    string vardai[n], pavardes[n];
    int pazymiai[k*n];
    double pazymiaiDouble[k*n], vidurkis[k];

    for(int i=0;i<k;i++){//nustatymas viso variable ant 0
        vidurkis[i]=0;
    }


    for(int i=0;i<k;i++){ //ivertinimo dalies irasymas
        cin >> dalis[i];
        //cout <<i<<": "<<dalis[i]<< endl;
    }




    for(int i=0;i<n;i++){
        cin>>vardai[i]; //vardu irasymas
        //cout <<"vardai "<<i<<": "<<vardai[i]<< endl;
        cin>>pavardes[i]; //pavardziu irasymas
        //cout <<"pavardes "<<i<<": "<<pavardes[i]<< endl;


        for(int j=0;j<k;j++){ //pazymiu irasymas
            cin>>pazymiai[j+(i*k)];
            //cout<<"pazymiai "<<j+(i*k)<<": "<<pazymiai[j+(i*k)]<< endl;
        }
    }

    //Pazymys*dalis skaiciavimas
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            pazymiaiDouble[j+(i*k)]=pazymiai[j+(i*k)]*dalis[j];
            //cout<<"x1= "<<pazymiai[j+(i*k)]<<" x2= "<<dalis[j]<<endl;
            //cout<<i<<" pazymiai: "<<pazymiaiDouble[j+(i*k)]<<endl;
            //cout<<"j+(i*k) means :"<< j+(i*k)<<endl;
        }
    }

    //Vidurkiu isvedimas
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            vidurkis[i]=vidurkis[i]+pazymiaiDouble[j+(i*k)];
            //cout<<"x1= "<<vidurkis[j+(i*k)]<<" x2= "<<pazymiaiDouble[j+(i*k)]<<endl;
            //cout<<i<<" pazymiai: "<<vidurkis[j]<<endl;
        }
    }

    //Suapvalinimas galutinio rezultato
    for(int i=0;i<n;i++){
        round(vidurkis[i]);
    }

    //SORT
        for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(vidurkis[i]<vidurkis[j]){
                swap(vardai[i], vardai[j]);
                swap(pavardes[i], pavardes[j]);
                swap(vidurkis[i], vidurkis[j]);
                //cout<<""<<endl;
                //cout<<"swapped "<<vardai[i]<<" with "<<vardai[j]<<endl;
                //cout<<"swapped "<<pavardes[i]<<" with "<<pavardes[j]<<endl;
                //cout<<"swapped "<<vidurkis[i]<<" with "<<vidurkis[j]<<endl;
                //cout<<""<<endl;
            }
        }
    }

    //VISI
    cout<<""<<endl;
    cout<<"VISI"<<endl;
    for(int i=0;i<n;i++){
        cout<<vardai[i]<<" "<<pavardes[i]<<" "<<vidurkis[i]<<endl;
    }
    cout<<""<<endl;


    //GERIAUSI
    cout<<"GERIAUSI"<<endl;
    cout<<vardai[0]<<" "<<pavardes[0]<<" "<<vidurkis[0]<<endl;
    cout<<""<<endl;

    //BLOGIAUSI
    cout<<"BLOGIAUSI"<<endl;
    cout<<vardai[n-1]<<" "<<pavardes[n-1]<<" "<<vidurkis[n-1]<<endl;


    return 0;
}
