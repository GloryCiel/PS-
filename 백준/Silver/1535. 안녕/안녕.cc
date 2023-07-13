#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    vector<int> life(N,0);
    vector<int> happiness(N,0);
    for(int i=0;i<N;++i)cin>>life[i];
    for(int i=0;i<N;++i)cin>>happiness[i];

    int res = 0;

    for(int i=0;i<(1<<N);++i)
    {
        int tmp1=0;
        int tmp2=0;
        for(int j=0;j<N;++j)
        {
            if(i&(1<<j))
            {
                tmp1+=life[j];
                tmp2+=happiness[j];
            }
        }
        if(tmp1<100)
            res = max(res,tmp2);
    }

    cout<<res;
}