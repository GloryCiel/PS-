#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;scanf("%d",&n);
    vector<int> number(n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&number[i]);
    }
    vector<int> dp(n);
    int ans = number[0];dp[0]=number[0];
    for(int i=1;i<n;++i)
    {
        dp[i]=max(dp[i-1]+number[i],number[i]);
        ans = max(dp[i],ans);
    }

    printf("%d",ans);

}