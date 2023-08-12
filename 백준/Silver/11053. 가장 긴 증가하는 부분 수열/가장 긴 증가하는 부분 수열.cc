#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    vector<int>sequence(N+1,0);
    for(int i=1;i<=N;++i)
    {
        cin>>sequence[i];
    }

    vector<int>dp(N+1,0);

    for(int i=1;i<=N;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(sequence[i]>sequence[j]) dp[i] = max(dp[j]+1,dp[i]);
        }
    }

    cout<<*max_element(dp.begin(),dp.end());


}