#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(const Graph &G, int v)
{
    seen[v] = true;
    cout<<v+1<<' ';

    for(auto next_v :G[v])
    {
        if(seen[next_v]) continue;
        dfs(G, next_v);
    }
}

void bfs(const Graph &G, int s)
{
    int N = (int)G.size();
    vector<int>dist(N,-1);
    queue<int> que;

    dist[s] = 0;
    que.push(s);

    while(!que.empty())
    {
        int v = que.front();
        cout<<v+1<<' ';
        que.pop();

        for(int x :G[v])
        {
            if(dist[x] != -1) continue;

            dist[x] = dist[v]+1;
            que.push(x);
        }
    }
}

int main()
{
    int N,M,V;cin>>N>>M>>V;

    Graph G(N);
    for(int i=0;i<M;++i)
    {
        int a,b;cin>>a>>b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    for(int i=0;i<N;++i)
    {
        sort(G[i].begin(),G[i].end());
    }
    seen.assign(N,false);
    dfs(G,V-1);
    cout<<endl;
    bfs(G,V-1);
}