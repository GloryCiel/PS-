#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;cin>>n;
    vector<int>triangle[n];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            int tmp;cin>>tmp;
            triangle[i].push_back(tmp);
        }
    }

    vector<vector<int>>dp(n,vector<int>(n,0));
    dp[0][0]=triangle[0][0];
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            if(j==0)
            {
                dp[i][j]=dp[i-1][j]+triangle[i][j];
            }
            else if(j==i)
            {
                dp[i][j]=dp[i-1][j-1]+triangle[i][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j-1]+triangle[i][j],dp[i-1][j]+triangle[i][j]);
            }
        }
    }
    int max = dp[n-1][0];
    for(int i=1;i<n;++i)
    {
        if(max<dp[n-1][i])max = dp[n-1][i];
    }
    cout<<max;
}