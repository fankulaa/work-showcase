#include <iostream>

using namespace std;

void nuskaitymas(int &n,int bar,int raud,int leps){
    cin>>n;
    int d,b,r,l;
    for(int i=0;i<n;i++){
        cin>>d>>b>>r>>l;
        bar[d]=bar[d]+d;
        raud[d]=raud[d]+r;
        leps[d]=leps[d]+l;
    }
}

void irasymas(int n,int bar[],int raud[],int leps[]){

    for(int i=1;i<32;i++){
        if(bar[i]!=0 || raud[i]!=0 || leps[i]!=0){
            cout<<i<<" "<<bar[i]<<" "<<raud[i]<<" "<<leps[i]<<endl;
        }
    }
}

int reset(int mas[], int n){

    for(int i=0;i<n;i++){
        mas[i]=0;
    }
}

int main()
{
    int n;
    cin>>n;
    int bar[32],raud[32],leps[32];
    reset(bar,32);
    reset(raud,32);
    reset(leps,32)

    nuskaitymas(n,bar,raud,leps)
    irasymas(bar)

    cout << "" << endl;
    return 0;
}
