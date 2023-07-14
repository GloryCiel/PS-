#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;cin>>N>>M;
    int six_min=1001;
    int one_min = 1001;
    int cnt = 0;

    for(int i=0;i<M;++i)
    {
        int tmp1,tmp2;cin>>tmp1>>tmp2;
        if(tmp1<six_min)
            six_min=tmp1;
        if(tmp2<one_min)
            one_min = tmp2;
    }

    if(one_min*6<=six_min)
        cnt=N*one_min;
    else
    {
        while(N>0)
        {
            if(N-6>=0)
            {
                cnt+=six_min;
                N=N-6;
            }
            else
            {
                int MIN=min(N*one_min,six_min);
                cnt+=MIN;
                break;
            }
        }
    }

    cout<<cnt;
}