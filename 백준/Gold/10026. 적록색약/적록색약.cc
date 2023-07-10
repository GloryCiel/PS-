#include<bits/stdc++.h>
using namespace std;

vector<int>up_down={-1,1,0,0};
vector<int>left_right={0,0,-1,1};

bool can_go(vector<vector<char>>picture,int i,int j)
{
    if(i<0 || i>=picture.size())
        return false;
    if(j<0 && j>=picture.size())
        return false;
    return true;
}

void bfs(int start_i,int start_j,vector<vector<char>> picture,vector<vector<bool>> &visited)
{
    queue<pair<int,int>>next;
    next.push(make_pair(start_i,start_j));
    visited[start_i][start_j]=true;
    while(!next.empty())
    {
        int now_i=next.front().first,now_j=next.front().second;
        next.pop();
        for(int i=0;i<4;++i)
        {
            if(can_go(picture,up_down[i]+now_i,left_right[i]+now_j)&&(!visited[now_i+up_down[i]][now_j+left_right[i]])&&(picture[now_i][now_j]==picture[now_i+up_down[i]][now_j+left_right[i]]))
            {
                next.push(make_pair(up_down[i]+now_i,left_right[i]+now_j));
                visited[now_i+up_down[i]][now_j+left_right[i]]=true;
            }
        }
    }
}

void color_blind_bfs(int start_i,int start_j,vector<vector<char>> picture,vector<vector<bool>> &visited)
{
    queue<pair<int,int>>next;
    next.push(make_pair(start_i,start_j));
    visited[start_i][start_j]=true;
    while(!next.empty())
    {
        int now_i=next.front().first,now_j=next.front().second;
        next.pop();
        for(int i=0;i<4;++i)
        {
            if(can_go(picture,up_down[i]+now_i,left_right[i]+now_j)&&(!visited[now_i+up_down[i]][now_j+left_right[i]])&&((picture[now_i][now_j]==picture[now_i+up_down[i]][now_j+left_right[i]])))
            {
                next.push(make_pair(up_down[i]+now_i,left_right[i]+now_j));
                visited[now_i+up_down[i]][now_j+left_right[i]]=true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    vector<vector<char>>picture(N,vector<char>(N,'0'));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
            cin>>picture[i][j];
    }

    int normal=0,color_blind=0;

    vector<vector<bool>>visited(picture.size(),vector<bool>(picture.size(),false));
    vector<vector<bool>>color_visited(picture.size(),vector<bool>(picture.size(),false));
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(!visited[i][j])
            {
                bfs(i,j,picture,visited);
                normal++;
            }
        }
    }

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(picture[i][j]=='G')
                picture[i][j]='R';
        }
    }

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            if(!color_visited[i][j])
            {
                color_blind_bfs(i,j,picture,color_visited);
                color_blind++;
            }
        }
    }
    
    cout<<normal<<' '<<color_blind;

}