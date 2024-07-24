#include <bits/stdc++.h>

using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string a,b;cin>>a>>b;

    int i,j;
    i = a.length();
    j = b.length();

    vector<vector<int>>dp(i+1,vector<int>(j+1,0));

    for(i=1;i<=a.length();++i) {
        for(j=1;j<=b.length();++j) {
            if(a[i-1]==b[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[a.length()][b.length()];


}