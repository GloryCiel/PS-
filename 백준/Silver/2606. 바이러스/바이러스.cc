#include <iostream>
#include<vector>

using namespace std;

void dfs(vector<bool> &,vector<int>[],int);
int connect = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    int M;cin>>M;

    vector<bool> visited(N,false);
    vector<int> graph[N];

    for(int i=0;i<M;++i)
    {
        int tmp1,tmp2;cin>>tmp1>>tmp2;
        tmp1-=1;tmp2-=1;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }
    dfs(visited,graph,0);
    cout<<connect;
}

void dfs(vector<bool> &visited, vector<int> graph[],int cur)
{
    visited[cur]=true;
    for(int i=0;i<graph[cur].size();++i)
    {
        int next = graph[cur][i];
        if(!visited[next])
        {
            dfs(visited,graph,next);
            connect++;
        }
    }
}