#include <iostream>

using namespace std;

int funkcija(int a,int b){

    int result;
    result= 2*a+9+b;
    return result;
}

int main()
{
    int x,y;
    cin>>x>>y;
    int rezultatas;
    rezultatas=funkcija(x,y);

    cout<<rezultatas;



    cout << "" << endl;
    return 0;
}
