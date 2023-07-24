#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>node[100001];

int MAX=-1,far=0;

void DFS(int now,int before,int cost)
{
    if(cost>MAX)
    {
        MAX = cost;
        far = now;
    }
    for(int i=0;i<node[now].size();++i)
    {
        if(node[now][i].first!=before)DFS(node[now][i].first,now,cost+node[now][i].second);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V;cin>>V;
    for(int i=0;i<V;++i)
    {
        int x;cin>>x;
        for(;;)
        {
            int y;cin>>y;
            if(y==-1)
                break;
            int z;cin>>z;
            node[x].push_back(make_pair(y,z));
        }
    }
    DFS(1,0,0);
    MAX = 0;
    DFS(far,0,0);
    cout<<MAX;


}