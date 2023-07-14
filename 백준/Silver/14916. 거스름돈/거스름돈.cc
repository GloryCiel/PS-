#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;cin>>n;
    vector<int>dp(100000,0);

    dp[1]=-1;dp[2]=1;dp[3]=-1;dp[4]=2;dp[5]=1;
    for(int i=6;i<=n;++i)
    {
        if(dp[i-2]!=-1)
        {
            dp[i]=dp[i-2]+1;
        }
        if(dp[i-5]!=-1)
        {
            dp[i]=min(dp[i-5]+1,dp[i]);
        }
        if(dp[i-2]==-1 &&dp[i-5]==-1)
            dp[i]=-1;
    }

    cout<<dp[n];

}