#include <iostream>

using namespace std;

int main()
{
    int detaleSum=0; //4paskutiniai skaiciai (if=0){break}
    int detaleSumMax=0; //4didziausias skaicius
    int detale1=0; //1det
    int detale2=0; //2det
    int detale3=0; //3det
    int detale4=0; //4det
    int detaleTotal=0; //is viso kiek pagaminta /cout

    cin>>detale1;
    detaleSum+=detale1;
    detaleSum-=detale2;
    detaleTotal+=detale1;
    cout<<"+d1: "<<detaleSum<<endl;

    while(detaleSum>0){

    cin>>detale2;
    detaleSum+=detale2;
    detaleSum-=detale3;
    detaleTotal+=detale2;
    cout<<"+d2: "<<detaleSum<<endl;

    cin>>detale3;
    detaleSum+=detale3;
    detaleSum-=detale4;
    detaleTotal+=detale3;
    cout<<"+d3: "<<detaleSum<<endl;

    cin>>detale4;
    detaleSum+=detale4;
    detaleSum-=detale1;
    detaleTotal+=detale4;
    cout<<"+d4: "<<detaleSum<<endl;

    cin>>detale1;
    detaleSum+=detale1;
    detaleSum-=detale2;
    detaleTotal+=detale4;
    cout<<"+d1: "<<detaleSum<<endl;

    if (detaleSum>detaleSumMax){
        detaleSumMax=detaleSum;
    }
    cout<<"Daugiausia detaliu per 1min:"<<detaleSumMax<<endl;

    cout<<"Is viso detaliu: "<<detaleSum<<endl;

    }


    //FAILED
    //FAILED

    //FAILED

    //FAILED
//FAILED
//FAILED
//FAILED
//FAILED

//FAILED
//FAILED
//FAILED
//FAILED
//FAILED

    cout << "Daugiausia detaliu per 1min: "<<detaleSumMax << endl;
    return 0;
}
