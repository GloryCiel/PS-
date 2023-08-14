#include<bits/stdc++.h>
#define INF 5000000
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E;cin>>V>>E;
    int K;cin>>K;
    vector<pair<int,int>>V_E[V+1];
    for(int i=0;i<E;++i)
    {
        int u,v,w;cin>>u>>v>>w;
        V_E[u].push_back(make_pair(v,w));
    }
    vector<int>distance(V+1,INF);

    priority_queue<pair<int,int>>pqueue;
    pqueue.push(make_pair(0,K));
    distance[K]=0;

    while(!pqueue.empty())
    {
        int dist = -pqueue.top().first;
        int now = pqueue.top().second;
        pqueue.pop();

        if(distance[now]<dist) continue;
        for(int i=0;i<V_E[now].size();++i)
        {
            int cost = dist+V_E[now][i].second;
            if(cost<distance[V_E[now][i].first])
            {
                distance[V_E[now][i].first]=cost;
                pqueue.push(make_pair(-cost,V_E[now][i].first));
            }
        }
    }

    for(int i=1;i<=V;++i)
    {
        if(distance[i]==INF) cout<<"INF"<<'\n';
        else cout<<distance[i]<<'\n';
    }
}