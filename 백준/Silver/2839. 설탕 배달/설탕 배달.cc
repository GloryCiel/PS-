#include<iostream>

using namespace std;

int main()
{
    int N;cin>>N;
    int *dp = new int[N+1];
    for(int i=0;i<N+1;++i) dp[i]=0;
    dp[3]=dp[5]=1;
    for(int i=6;i<N+1;++i)
    {
        if(dp[i-3]) dp[i]=dp[i-3]+1;
        if(dp[i-5])dp[i]=dp[i]?min(dp[i],dp[i-5]+1):dp[i-5]+1;
    }
    if(dp[N]==0)
        cout<<-1<<endl;
    else
        cout<<dp[N]<<endl;
}