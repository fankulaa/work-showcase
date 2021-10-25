#include <iostream>

using namespace std;



void irasymas(string vardai[], string pavarde[], int amziai[], int n){

    for(int i=0;i<n;i++){
        cout<<vardai[i]<<" "<<pavarde[i]<<" "<<amziai[i]<<endl;
    }


}

void spausdinimas(string vardai[], string pavarde, int amziai[],int n){

    for(int i=0;i<n;i++){
        cout<<i+1<<"."<<vardai[i]<<" "<<pavarde[i]<<" "<<amziai[i]<<" "<<pilna[i]<<endl;
    }
}

bool pilnaF(int a){


        if (a>17)return true;
            else return false;
}

void pilna(int metai[], int n, bool ar[]){

    for(int i=0;i<n;i++){
        if(pilnaF(metai[i]))
            ar[i]=true;
        }else{
            ar[i]=false;
        }
}


int main()
{
    int n;
    cin<<n;
    string vardai[n],pavardes[n];
    int gimimo[n];
    bool pilnametis[n];

    irasymas(vardai,pavardes,gimimo,n);
    pilnametis(vardai,pavardes,gimimo,n);
    spausdinimas(vardai, pavardes,gimimo,n);

    cout << "Hello world!" << endl;
    return 0;
}
