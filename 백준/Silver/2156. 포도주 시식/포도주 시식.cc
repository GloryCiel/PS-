#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;

    vector<int>wine;
    vector<int>dp;

    for(int i=0;i<3;++i)
    {
        wine.push_back(0);
        dp.push_back(0);
    }

    for(int i=0;i<N;++i)
    {
        int tmp;cin>>tmp;
        wine.push_back(tmp);
    }

    for(int i=3;i<wine.size();++i)
    {
        int tmp = max(dp[i-3]+wine[i-1]+wine[i],dp[i-2]+wine[i]);
        dp.push_back(max(tmp,dp[i-1]));
    }

    cout<<dp[wine.size()-1];
}