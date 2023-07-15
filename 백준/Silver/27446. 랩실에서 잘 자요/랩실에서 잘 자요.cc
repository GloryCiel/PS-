#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;cin>>N>>M;
    vector<bool>is_in(M+1,false);
    vector<int>to_print;
    for(int i=0;i<M;++i)
    {
        int tmp;cin>>tmp;
        is_in[tmp]=true;
    }

    for(int i=1;i<=N;++i)
    {
        if(!is_in[i])
            to_print.push_back(i);
    }

    if(to_print.size()==0)
        cout<<0;

    else if(to_print.size()==1)
        cout<<7;

    else
    {
        vector<int>dp(N+1,0);
        int start = to_print[0];int idx = 1;int cnt=1;
        dp[start]=7;
        for(int i=start+1;i<dp.size();++i)
        {
            if(i!=to_print[idx])
            {
                dp[i]=dp[i-1];
                cnt++;
            }
            else
            {
                dp[i]=min(dp[i-1]+7,dp[i-1]+2*cnt);
                cnt=1;
                if(idx+1<to_print.size())
                    idx++;
            }
        }
        cout<<dp[N];
    }



}