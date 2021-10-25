#include <iostream>

using namespace std;

int main()
{
    int dienuKiekis=0;
    int atstumas=0;
    int dienos=0;
    float vidurkis;

    cin>>dienos;

    while(dienos>0){

        dienuKiekis++;
        atstumas+=dienos;
        cin>>dienos;
    }



    vidurkis=(float)atstumas/dienuKiekis;

    cout << "Dienu kiekis: "<<dienuKiekis<<endl;
    cout<<"Atstumas bendras: "<< atstumas<< endl;
    cout<<"Vidurkis: "<< vidurkis<<endl;
    return 0;
}
