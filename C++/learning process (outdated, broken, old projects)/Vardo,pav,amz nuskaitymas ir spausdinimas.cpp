#include <iostream>

using namespace std;

void atspausdinti(char a,char b,int c){

    cout<<a<<b<<" "<<c;
}



int main()
{
    string vardas, pavarde;
    int amzius;

    cin>>vardas;
    cin>>pavarde;
    cin>>amzius;


    atspausdinti(vardas[0],pavarde[0],amzius);


    cout << "" << endl;
    return 0;
}
