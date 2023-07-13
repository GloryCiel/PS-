#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int>>board(500,vector<int>(500,0));
vector<vector<int>>Move={{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<bool>>visited(500,vector<bool>(500,false));
int result=0;

bool chk(int i,int j)
{
    if(i<0||i>=N||j<0||j>=M)return false;
    return true;
}

void visit_reset()
{
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)visited[i][j]=false;
}

void dfs(int i,int j, int depth, int sum)
{
    if(depth==3)
    {
        result = max(result,sum);
        return;
    }
    for(int a=0;a<4;++a)
    {
        int next_i = i+Move[a][0];
        int next_j = j+Move[a][1];
        if(!chk(next_i,next_j))continue;
        if(visited[next_i][next_j])continue;
        visited[next_i][next_j]=true;
        dfs(next_i,next_j,depth+1,sum+board[next_i][next_j]);
        visited[next_i][next_j]=false;
    }
}

void first(int i,int j)
{
    int sum = 0;
    sum = board[i][j]+board[i][j+1]+board[i][j+2]+board[i-1][j+1];
    result = max(result,sum);
}

void second(int i,int j)
{
    int sum = 0;
    sum = board[i][j]+board[i][j+1]+board[i][j+2]+board[i+1][j+1];
    result = max(result,sum);
}

void third(int i, int j)
{
    int sum = 0;
    sum = board[i][j]+board[i+1][j]+board[i+2][j]+board[i+1][j+1];
    result = max(result,sum);
}

void fourth(int i,int j)
{
    int sum = 0;
    sum = board[i][j]+board[i-1][j+1]+board[i][j+1]+board[i+1][j+1];
    result = max(result,sum);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            cin>>board[i][j];

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
        {
            visited[i][j]=true;
            dfs(i,j,0,board[i][j]);
            visited[i][j]=false;
            if(i-1>=0 && j+2<M)first(i,j);
            if(j+2<M && i+1<N)second(i,j);
            if(i+2<N &&j+1<M)third(i,j);
            if(i+1<N && i-1>=0&&j+1<M)fourth(i,j);
        }
    }

    cout<<result;

}