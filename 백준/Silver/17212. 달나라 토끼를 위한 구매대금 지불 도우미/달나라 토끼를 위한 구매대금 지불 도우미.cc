#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    vector<int>coin(4,0);
    coin[0]=1,coin[1]=2,coin[2]=5,coin[3]=7;
    vector<int>dp(N+7,0);
    dp[1]=1,dp[2]=1,dp[3]=2,dp[4]=2,dp[5]=1,dp[6]=2,dp[7]=1;

    for(int i=8;i<=N;++i)
    {
        int Min = 10000000;
        for(int j=0;j<4;++j)
        {
            Min = min(Min,dp[i-coin[j]]+1);
        }
        dp[i]=Min;
    }
    
    cout<<dp[N];

}