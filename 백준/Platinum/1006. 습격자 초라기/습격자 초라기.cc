#include <bits/stdc++.h>

#define INF 987654321

using namespace std;

int arr[2][10001];
int dp[10001][3];
int n,w;

void solve() {
    for(int i=2;i<=n;++i) {
        int up = arr[0][i-1]+arr[0][i]<=w?1:2;
        int down = arr[1][i-1]+arr[1][i]<=w?1:2;
        int ver = arr[0][i]+arr[1][i]<=w?1:2;

        dp[i][0] = min({ dp[i - 1][0] + ver, dp[i - 2][0] + up + down,dp[i - 1][1] + up + 1,dp[i - 1][2] + 1 + down });
        dp[i][1] = min(dp[i - 1][2] + down, dp[i - 1][0] + 1);
        dp[i][2] = min(dp[i - 1][1] + up, dp[i - 1][0] + 1);
    }
    return;
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t;cin>>t;

    while(t--) {
        memset(dp,0,sizeof(dp));
        cin>>n>>w;

        for(int i=0;i<2;++i) {
            for(int j=1;j<=n;++j)
                cin>>arr[i][j];
        }
        int t_up = arr[0][1];
        int t_down = arr[1][1];

        int ans =INF;

        dp[1][0] = arr[0][1] + arr[1][1] <= w ? 1 : 2;
        dp[1][1] = dp[1][2] = 1;
        solve();
        ans = min(ans, dp[n][0]);

        if (arr[0][1] + arr[0][n] <= w) {
            dp[1][0] = 2;
            dp[1][1] = dp[1][2] = 1;
            arr[0][1] = INF;
            solve();
            ans = min(ans, dp[n][1]);
            arr[0][1] = t_up;
        }

        if (arr[1][1] + arr[1][n] <= w) {
            dp[1][0] = 2;
            dp[1][1] = dp[1][2] = 1;
            arr[1][1] = INF;
            solve();
            ans = min(ans, dp[n][2]);
            arr[1][1] = t_down;
        }

        if (arr[0][1] + arr[0][n] <= w && arr[1][1] + arr[1][n] <= w) {
            arr[0][1] = arr[1][1] = INF;
            dp[1][0] = 2;
            dp[1][1] = dp[1][2] = 1;
            solve();
            ans = min(ans, dp[n - 1][0]);
            arr[0][1] = t_up;
            arr[1][1] = t_down;
        }

        if (n == 1)
            ans = arr[0][1] + arr[1][1] <= w ? 1 : 2;

        cout<<ans<<'\n';
    }
}