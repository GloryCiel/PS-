#include <bits/stdc++.h>

using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num[] ={3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
    //65빼면 됨

    string A,B;cin>>A>>B;

    vector<int>nums;
    for(int i=0;i<A.size();++i)
    {
        nums.push_back(num[A[i]-65]);
        nums.push_back(num[B[i]-65]);
    }

    vector<vector<int>>dp(nums.size()-1,vector<int>(nums.size(),0));

    for(int i=0;i<nums.size();++i)
    {
        dp[0][i]=nums[i];
    }
    int cnt = nums.size()-1;
    for(int i=1;i<nums.size()-1;++i)
    {
        for(int j=0;j<cnt;++j)
        {
            dp[i][j]=(dp[i-1][j]+dp[i-1][j+1])%10;
        }
        cnt--;
    }
    cout<<dp[nums.size()-2][0]<<dp[nums.size()-2][1];


}