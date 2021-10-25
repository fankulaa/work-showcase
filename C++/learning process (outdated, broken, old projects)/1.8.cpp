#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, z,x;
    cin>>n>>z>>x;
    float islaidos,santaupos,skrynios;
    islaidos=round(n*0.65/12*100)/100;
    santaupos=n*0.335*x;
    skrynios=santaupos/z;
    skrynios=ceil(skrynios);

    cout << islaidos<<" "<< skrynios << endl;
    return 0;
}
