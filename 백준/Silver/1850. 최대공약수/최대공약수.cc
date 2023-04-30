#include<iostream>
#include<cmath>
using namespace std;

int solution(unsigned long long a,unsigned long long b)
{
    if(a%b==0)
        return (int)b;
    else
        return solution(b,a%b);
}

int main()
{
    unsigned long long a,b;cin>>a>>b;
    int Sol = solution(a,b);
    for(int i=0;i<Sol;++i)
        cout<<1;
}