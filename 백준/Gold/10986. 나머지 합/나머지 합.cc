#include <bits/stdc++.h>


using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N,M;cin>>N>>M;
    vector<long long>sequence(N);
    vector<long long>cnt(M);
    long long ans = 0;


    for (long long i=0;i<N;++i)
    {
        long long tmp;cin>>tmp;
        if (i==0)sequence[i]=tmp;
        else sequence[i]=sequence[i-1]+tmp;
    }

    for (long long i=0;i<N;++i)
    {
        long long r = sequence[i]%M;
        if (r==0)ans++;
        cnt[r]++;
    }
    for (long long i=0;i<M;++i)
    {
        if (cnt[i]>1)
            ans +=(cnt[i]*(cnt[i]-1)/2);
    }
    cout<<ans;

}