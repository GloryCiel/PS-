#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;cin>>n;
    vector<int> dp (n+1,0);
    dp[1]=1;

    for(int i=2;i<n+1;++i)
    {
        dp[i] = dp[1]+dp[i-1];
        for(int j=2;j*j<=i;j++)
        {
            dp[i] = min(dp[i],1+dp[i-j*j]);
        }
    }

    cout<<dp[n];

}