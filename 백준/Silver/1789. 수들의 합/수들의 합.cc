#include<bits/stdc++.h>
using namespace std;

long long sum(long long n)
{
    return n*(n+1)/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int S;cin>>S;
    long long N;
    for(long long i=1;sum(i)<=S;++i)
        N=i;

    cout<<N;
}