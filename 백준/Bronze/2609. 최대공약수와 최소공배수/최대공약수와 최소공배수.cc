#include <iostream>
using namespace std;

int GCD(int, int);
int LCM(int, int);

int main()
{
    int a,b;cin>>a>>b;
    cout<<GCD(a,b)<<'\n'<<LCM(a,b);
}

int GCD(int a,int b)
{
    if(a<b)
        return GCD(b,a);
    if(!(a%b))
        return b;
    else
        return GCD(b,a%b);
}
int LCM(int a,int b)
{
    return a*b/GCD(a,b);
}