#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,V;cin>>N>>M>>V;
    vector<int>save(N+1,0);
    for(int i=1;i<=N;++i)
    {
        cin>>save[i];
    }

    for(int i=0;i<M;++i)
    {
        int move;cin>>move;
        if(N!=V)
        {
            if(move<N)
                cout<<save[1+move]<<'\n';
            else
            {
                int div=(move-N)%(N-V+1);
                cout<<save[3+div]<<'\n';
            }
        }
        else
        {
            if(move<N)
                cout<<save[1+move]<<'\n';
            else
                cout<<save[V]<<'\n';
        }
    }
}
