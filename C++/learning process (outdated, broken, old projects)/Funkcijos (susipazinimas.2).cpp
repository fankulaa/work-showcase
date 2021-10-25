#include <iostream>

using namespace std;

bool pilnametis(int a){

    if(a>17) return true;
        else return false;
}

int main()
{
    string vardas,pavarde;
    int amzius;
    cin>>vardas>>pavarde>>amzius;
    if(pilnametis(amzius)) cout<<vardas<<" Taip"<<endl;
        else cout<<vardas<< " NE"<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
