#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;cin>>N>>K;
    int ans;

    int Left = 1, Right = K;
    while(Left<=Right)
    {
        int Mid = (Left+Right)/2;
        int cnt = 0;
        for(int i=1;i<=N;++i)
            cnt+=min(Mid/i,N);
        if(cnt<K)
        {
            Left=Mid+1;
        }
        else if(cnt>=K)
        {
            Right = Mid-1;
            ans = Mid;
        }
    }
    cout<<ans<<'\n';
}