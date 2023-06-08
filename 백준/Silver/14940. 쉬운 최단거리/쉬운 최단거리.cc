#include<iostream>
#include<queue>
#include<vector>

using namespace std;

bool range(int i,int j,int M,int N)
{
    if(i>=0 && i<N)
    {
        if(j>=0 && j<M)
            return true;
    }
    return false;
}

void bfs(vector<vector<int>> &graph,vector<vector<bool>> &visited,queue<pair<int,int>> axis)
{
    int J[] = {0, 0, -1, 1};
    int I[] = {-1, 1, 0, 0};
    int dist = 1;
    while(!axis.empty())
    {
        int i = axis.front().first;
        int j = axis.front().second;
        visited[i][j]=true;
        axis.pop();
        for(int a=0;a<4;++a)
        {
            int next_i = i+I[a];
            int next_j = j+J[a];
            if(range(next_i,next_j,graph[0].size(),graph.size())&&graph[next_i][next_j]==1&&visited[next_i][next_j]==false)
            {
                graph[next_i][next_j] = graph[i][j]+1;
                axis.push(make_pair(next_i,next_j));
            }
            else if(range(next_i,next_j,graph[0].size(),graph.size()) && graph[next_i][next_j]==0&&visited[next_i][next_j]==false)
            {
                graph[next_i][next_j]=0;
            }
        }
    }
}

int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> land(n,vector<int>(m,0));
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<pair<int,int>> dist;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>land[i][j];
            if(land[i][j]==2)
            {
                dist.push(make_pair(i,j));
                land[i][j]=0;
            }
        }
    }
    bfs(land,visited,dist);

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(land[i][j]==1 && !visited[i][j])
                land[i][j]=-1;
        }
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            cout<<land[i][j]<<' ';
        cout<<endl;
    }
}