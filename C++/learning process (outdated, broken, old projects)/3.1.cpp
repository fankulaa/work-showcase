#include <iostream>

using namespace std;

int main()
{
    int b,f;
    cin>>b;//kiek ilga bus seka
    int a[b];
    for(int i=0;i<b;i++){
        a[i]=1;
        if(i>=3){
            a[i]=a[i-1]+a[i-2]+a[i-3]; //formule
        }
    }
    cout<<a[b-1]<<endl;
    cout << "" << endl;
    return 0;
}
