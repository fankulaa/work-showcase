#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float p1,p2,p3,s,pf;
    cin >>p1>>p2>>p3>>s;

    pf=round(((p1+p2+p3)*1.21+s)*100)/100;

    cout << pf << endl;
    return 0;
}
