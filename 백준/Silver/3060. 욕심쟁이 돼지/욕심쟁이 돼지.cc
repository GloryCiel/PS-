#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;cin>>T;
    while(T--)
    {
        int ans = 1;
        int N;cin>>N;
        vector<int>food(6,0);
        int tmp=0;
        for(int i=0;i<6;++i)
        {
            cin>>food[i];
            tmp+=food[i];
        }
        while(tmp<=N)
        {
            tmp*=4;
            ans++;
        }
        cout<<ans<<'\n';
    }

}