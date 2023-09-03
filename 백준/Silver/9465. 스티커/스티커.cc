#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;cin>>T;
    while(T--)
    {
        int n;cin>>n;
        vector<vector<int>>stickers(2,vector<int>(n+1,0));
        for(int i=0;i<2;++i)
        {
            for(int j=0;j<n;++j)
            {
                cin>>stickers[i][j+1];
            }
        }

        vector<vector<int>>dp(2,vector<int>(n+1,0));
        dp[0][1]=stickers[0][1],dp[1][1]=stickers[1][1];
        for(int i=2;i<=n;++i)
        {
            dp[0][i]=max(dp[1][i-2]+stickers[0][i],dp[1][i-1]+stickers[0][i]);
            dp[1][i]=max(dp[0][i-2]+stickers[1][i],dp[0][i-1]+stickers[1][i]);
        }
        cout<<max(dp[0][n],dp[1][n])<<'\n';
    }
}
