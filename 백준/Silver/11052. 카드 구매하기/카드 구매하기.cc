#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    vector<int>price(N+1,0);
    vector<int>dp(N+1,0);
    for(int i=1;i<=N;++i)
        cin>>price[i];

    dp[1] = price[1];

    for(int i=2;i<=N;++i)
    {
        for(int j=1;j<=i;++j)
        {
            dp[i] = max(dp[i],price[j]+dp[i-j]);
        }
    }

    cout<<dp[N];

}