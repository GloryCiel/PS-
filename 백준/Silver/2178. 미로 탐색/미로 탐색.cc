#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;


void bfs(queue<pair<int,int>>&,vector<vector<bool>>&,vector<vector<int>>,vector<vector<int>>&,int,int);
bool is_road(int, int,vector<vector<int>>,vector<vector<bool>>,int,int,int,int);

int main()
{
    int N,M;scanf("%d %d\n",&N,&M);

    vector<vector<int>>maze(N,vector<int>(M,0));
    vector<vector<bool>>visited(N,vector<bool>(M,false));
    vector<vector<int>>chk(N,vector<int>(M,0));
    queue<pair<int,int>>to_visit;

    for(int i=0;i<N;++i)
    {
        string tmp;getline(cin,tmp);
        for(int j=0;j<M;++j)
        {
            maze[i][j]=tmp[j]-'0';
        }
    }
    to_visit.push(make_pair(0,0));
    visited[0][0]=true;
    bfs(to_visit,visited,maze,chk,N,M);
    printf("%d",chk[N-1][M-1]+1);
}

void bfs(queue<pair<int,int>>& to_visit,vector<vector<bool>>& visited,vector<vector<int>> maze,vector<vector<int>>&chk,int N,int M)
{
    vector<int> A={0,1,0,-1};
    vector<int> B = {1,0,-1,0};//우,하,좌,상 순서
    while(!to_visit.empty())
    {
        int a,b;//i,j
        a = to_visit.front().first,b=to_visit.front().second;
        to_visit.pop();
        if(a==N && b==M)
            return;
        for(int i=0;i<4;++i)
        {
            if(is_road(N,M,maze,visited,a,b,A[i],B[i]))
            {
                to_visit.push(make_pair(a+A[i],b+B[i]));
                visited[a+A[i]][b+B[i]]=true;
                chk[a+A[i]][b+B[i]]=chk[a][b]+1;
            }
        }
    }
}

bool is_road(int N, int M,vector<vector<int>>maze,vector<vector<bool>>visited,int i,int j,int m_i,int m_j)
{
    if(i+m_i<0 ||i+m_i>=N ||j+m_j<0 ||j+m_j>=M)
        return false;
    if(maze[i+m_i][j+m_j]==0)
        return false;
    if(visited[i+m_i][j+m_j])
        return false;
    return true;
}