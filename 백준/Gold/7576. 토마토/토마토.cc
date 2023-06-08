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

void bfs(vector<vector<int>> &graph,queue<pair<int,int>> tomato)
{
    int J[] = {0, 0, -1, 1};
    int I[] = {-1, 1, 0, 0};
    while (!tomato.empty())
    {
        int x = tomato.front().first;//i
        int y = tomato.front().second;//j
        tomato.pop();

        for(int i=0;i<4;++i)
        {
            int next_i = x+I[i];
            int next_j = y+J[i];
            if(range(next_i,next_j,graph[0].size(),graph.size()) && graph[next_i][next_j]==0)
            {
                graph[next_i][next_j] = graph[x][y]+1;
                tomato.push(make_pair(next_i,next_j));
            }
        }
    }
}

int main()
{
    int M,N;cin>>M>>N;
    vector<vector<int>> box(N,vector<int> (M,0));
    queue<pair<int,int>>tomato;

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            cin>>box[i][j];
            if(box[i][j]==1)
                tomato.push(make_pair(i,j));
        }
    }
    bfs(box,tomato);

    int day = 0;

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            if(box[i][j]==0)
            {
                cout<<-1<<endl;
                return 0;
            }
            if(day<box[i][j])
            {
                day = box[i][j];
            }
        }
    }
    cout<<day-1<<endl;
}