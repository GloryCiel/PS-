#include <bits/stdc++.h>

using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;cin>>n;

    vector<int>dp(n+1,0);
    dp[0]=0;dp[1]=1;dp[2]=2;
    if(n>=3)
    {
        for(int i=3;i<n+1;++i)
        {
            dp[i]=(dp[i-1]+dp[i-2])%10;
        }
    }
    cout<<dp[n];

}