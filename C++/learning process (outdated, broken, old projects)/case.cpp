#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;


    cout<<"Menuo: ";
    switch (n){

    case 1: cout<<"Sausis"<<endl;break;
    case 2: cout<<"Vasaris"<<endl;break;
    case 3: cout<<"Kovas"<<endl;break;
    case 4: cout<<"Balandis"<<endl;break;
    case 5: cout<<"Geguzė"<<endl;break;
    case 6: cout<<"Birzelis"<<endl;break;
    case 7: cout<<"Liepa"<<endl;break;
    case 8: cout<<"Rugpjutis"<<endl;break;
    case 9: cout<<"Rugsejis"<<endl;break;
    case 10: cout<<"Spalis"<<endl;break;
    case 11: cout<<"Lapkritis"<<endl;break;
    case 12: cout<<"Groudis"<<endl;break;

    default : cout<<"wtf"<<endl;break;
    }


    cout<<"Sezonas: ";
    switch (n){

    case 1:
    case 2:
    case 3: cout<<"Pavasaris"<<endl;break;
    case 4:
    case 5:
    case 6: cout<<"Vasara"<<endl;break;
    case 7:
    case 8:
    case 9: cout<<"Ruduo"<<endl;break;
    case 10:
    case 11:
    case 12: cout<<"Ziema"<<endl;break;

    default : cout<<"wtf"<<endl;break;
    }


    return 0;
}
