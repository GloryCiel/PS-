#include<iostream>
using namespace std;

int sol(int a, int b)
{
    int permutation=1;
    for(int i=0;i<b;++i)
    {
        permutation*=(a-i);
    }
    int factorial=1;
    for(int i=b;i>=1;--i)
    {
        factorial*=i;
    }
    return (permutation/factorial);
}

int main()
{
    int N,K;cin>>N>>K;
    cout<<sol(N,K)<<endl;
}