#include <bits/stdc++.h>

using namespace std;

vector<int>y={1,-1,0,0};
vector<int>x={0,0,1,-1};//D,U,R,L

int K;//몇 개인지
int res=0;


void dfs(vector<vector<char>>,vector<vector<bool>>,int,int,int);
bool can_go(int,int,int,int);

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int R,C;cin>>R>>C>>K;

    vector<vector<char>>graph(R,vector<char>(C));
    vector<vector<bool>>visited(R,vector<bool>(C,false));

    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;++j)
            cin>>graph[i][j];
    }
    visited[R-1][0]=true;
    dfs(graph,visited,0,R-1,1);
    cout<<res;

}

void dfs(vector<vector<char>>graph,vector<vector<bool>>visited,int X,int Y,int cnt)
{
    if(X==graph[0].size()-1 && Y==0)
    {
        if(cnt==K)
        {
            res++;
        }
    }
    for(int i=0;i<4;++i)
    {
        if(can_go(graph[0].size(),graph.size(),X+x[i],Y+y[i]))
        {
            if(!visited[Y+y[i]][X+x[i]] && graph[Y+y[i]][X+x[i]]!='T')
            {
                visited[Y+y[i]][X+x[i]]=true;
                dfs(graph,visited,X+x[i],Y+y[i],cnt+1);
                visited[Y+y[i]][X+x[i]]=false;
            }
        }
    }

}

bool can_go(int Given_x,int Given_y, int X, int Y)
{
    if (X<0 || X>=Given_x)
        return false;
    if(Y<0 || Y>=Given_y)
        return false;
    return true;
}