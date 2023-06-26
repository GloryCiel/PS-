#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;cin>>N>>K;
    vector<int>coin(N,0);
    for(int i=0;i<N;++i)
    {
        cin>>coin[i];
    }

    int res = 0;
    for(int i=N-1;i>=0;--i)
    {
        if(K==0)
            break;
        else if(K/coin[i]!=0)
        {
            res+=K/coin[i];
            K = K%coin[i];
        }
    }
    cout<<res;
}