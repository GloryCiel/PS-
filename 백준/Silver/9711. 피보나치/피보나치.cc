#include <bits/stdc++.h>

using namespace std;


long long fibo(int n,int Q)
{
    vector<long long>memo(n+2,-1);
    memo[0]=0;
    memo[1]=1;
    memo[2]=1;
    for(int i=3;i<n+2;++i)
    {
        memo[i]=(memo[i-1]+memo[i-2])%Q;
    }
    return memo[n];
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int T;cin>>T;
    for(int i=0;i<T;++i)
    {

        int P,Q;cin>>P>>Q;
        long long a=fibo(P,Q);
        cout<<"Case #"<<i+1<<": "<<a%Q<<'\n';
    }

}