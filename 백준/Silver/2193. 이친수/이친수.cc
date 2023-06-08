#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;cin>>N;
    vector<long long> dp(N+1,0);
    dp[0]=0;dp[1]=1;dp[2]=1;
    for(int i=3;i<N+1;++i)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[N];
}