#include <iostream>

using namespace std;

int factorial(int n){
    int ats=0;
    if(n!=0){
        ats=n*factorial(n-1);
    } else{
        return 1;
    }
    return ats;
}

int main()
{
    int n;
    cin>>n;
    cout << factorial(n) << endl;
    return 0;
}
