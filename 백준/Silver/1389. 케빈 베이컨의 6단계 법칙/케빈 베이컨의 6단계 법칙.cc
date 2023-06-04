#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Graph = vector<vector<int>>;

int bfs(const Graph &G, int s)
{
    int N = (int)G.size();
    vector<int>dist(N,-1);
    queue<int> que;

    dist[s] = 0;
    que.push(s);

    while(!que.empty())
    {
        int v = que.front();
        que.pop();

        for(int x :G[v])
        {
            if(dist[x] != -1) continue;

            dist[x] = dist[v]+1;
            que.push(x);
        }
    }
    int result = 0;
    for(int i=0;i<N;++i)
        result+=dist[i];
    return result;
}

int main()
{
    int N,M;cin>>N>>M;

    Graph G(N);
    for(int i=0;i<M;++i)
    {
        int a,b;cin>>a>>b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    for(int i=0;i<N;++i)
    {
        sort(G[i].begin(), G[i].end());
    }
    int person = 0, min = bfs(G,0);
    for(int i=1;i<N;++i)
    {
        int tmp = bfs(G,i);
        if(tmp<min)
        {
            min = tmp;
            person = i;
        }
    }
    cout<<person+1;
}