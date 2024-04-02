#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;cin>>N;//0,1,2,3,4,5,6,7,8,9,10,20,21,.....,9876543210

    vector<long long>dp(N+11,0);
    queue<long long>Q;

    for(int i=1;i<=9;++i)
    {
        Q.push(i);
        dp[i]=i;
    }

    if(N<=10)
    {
        cout<<N;
        return 0;
    }

    int idx = 10;
    while(idx<=N && !Q.empty())
    {
        long long num = Q.front();
        Q.pop();
        int last_digit = num%10;

        for(int i=0;i<last_digit;++i)
        {
            Q.push(10*num+i);
            dp[idx++]=10*num+i;
        }
    }
    if(idx>=N && dp[N]!=0)
        cout<<dp[N];
    else
        cout<<-1;

}