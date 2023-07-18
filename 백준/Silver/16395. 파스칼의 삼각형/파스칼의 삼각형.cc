#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;cin>>N>>K;

    vector<int>dp[N+1];
    dp[0].push_back(1);
    dp[1].push_back(1);
    dp[1].push_back(1);
    for(int i=2;i<N;++i)
    {
        dp[i].push_back(1);
        for(int j=1;j<i;++j)
            dp[i].push_back(dp[i-1][j-1]+dp[i-1][j]);
        dp[i].push_back(1);
    }

    cout<<dp[N-1][K-1];
}