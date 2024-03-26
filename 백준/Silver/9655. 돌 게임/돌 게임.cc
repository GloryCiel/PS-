#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;cin>>N;
    vector<int>dp(N+2,0);
    dp[0]=0;dp[1]=1;dp[2]=2;
    if(N<=2)
    {
        if(N==1)cout<<"SK";
        else cout<<"CY";
        return 0;
    }
    for(int i=3;i<=N;++i)
    {
        dp[i]=min(dp[i-1]+1,dp[i-3]+1);
    }
    if(dp[N]%2)cout<<"SK";
    else cout<<"CY";
}