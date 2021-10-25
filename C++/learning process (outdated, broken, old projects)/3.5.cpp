#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;

    for(int i=a;i<=b;i++){
        if (i%4==0){
            int kelintas;
            kelintas=(i-1960)/4+1;
            cout<<kelintas<<endl;
        }
    }


    cout << "" << endl;
    return 0;
}
