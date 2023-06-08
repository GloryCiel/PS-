#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;cin>>K;
    vector<vector<int>>dp(2,vector<int>(K+1,0));
    dp[0][0]=1,dp[1][0]=0;
    for(int i=1;i<K+1;++i)
    {
        dp[0][i]=dp[1][i-1];
        dp[1][i]=dp[0][i-1]+dp[1][i-1];
    }
    cout<<dp[0][K]<<' '<<dp[1][K]<<'\n';
}