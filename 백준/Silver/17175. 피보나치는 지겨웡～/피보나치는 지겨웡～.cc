#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;cin>>n;
    vector<int>dp(n+2,0);
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=n;++i)
    {
        dp[i]=(1+dp[i-1]+dp[i-2])%1000000007;
    }
    cout<<dp[n];
}