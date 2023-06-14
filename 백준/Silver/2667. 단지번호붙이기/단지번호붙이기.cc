#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;


int bfs(queue<pair<int,int>>&,vector<vector<bool>>&,vector<vector<int>>,vector<vector<int>>&,int,int,int);
bool is_road(int, int,vector<vector<int>>,vector<vector<bool>>,int,int,int,int);

int main()
{
    int N;scanf("%d\n",&N);

    vector<vector<int>>maze(N,vector<int>(N,0));
    vector<vector<bool>>visited(N,vector<bool>(N,false));
    vector<vector<int>>chk(N,vector<int>(N,0));
    queue<pair<int,int>>to_visit;
    vector<int>to_sort;

    for(int i=0;i<N;++i)
    {
        string tmp;getline(cin,tmp);
        for(int j=0;j<N;++j)
        {
            maze[i][j]=tmp[j]-'0';
        }
    }

    int first =1;
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(maze[i][j]==1 && !visited[i][j])
            {
                to_visit.push(make_pair(i,j));
                visited[i][j]=true;
                chk[i][j]=first;
                to_sort.push_back(bfs(to_visit,visited,maze,chk,N,N,first));
                first++;
            }
        }
    }

    printf("%d\n",first-1);
    sort(to_sort.begin(),to_sort.end());
    for(int i=0;i<to_sort.size();++i)
        printf("%d\n",to_sort[i]);

}

int bfs(queue<pair<int,int>>& to_visit,vector<vector<bool>>& visited,vector<vector<int>> maze,vector<vector<int>>&chk,int N,int M,int first)
{
   int res = 0;
    vector<int> A={0,1,0,-1};
    vector<int> B = {1,0,-1,0};//우,하,좌,상 순서
    while(!to_visit.empty())
    {
        int a,b;//i,j
        a = to_visit.front().first,b=to_visit.front().second;
        to_visit.pop();
        for(int i=0;i<4;++i)
        {
            if(is_road(N,M,maze,visited,a,b,A[i],B[i]))
            {
                to_visit.push(make_pair(a+A[i],b+B[i]));
                visited[a+A[i]][b+B[i]]=true;
                chk[a+A[i]][b+B[i]]=first;
                res++;
            }
        }
    }
    return res+1;
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