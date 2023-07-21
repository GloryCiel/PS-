#include<bits/stdc++.h>
using namespace std;

void dfs(int N,int M,int now,int cnt, vector<bool>&visited,vector<int>&print)
{
    if(cnt==M)
    {
        for(int i=0;i<M;++i)
        {
            cout<<print[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=now;i<=N;++i)
    {
        if(!visited[i])
        {
            visited[i]=true;
            print[cnt]=i;
            dfs(N,M,i+1,cnt+1,visited,print);
            visited[i]=false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;cin>>N>>M;
    vector<bool>visited(N,false);
    vector<int>print(9,0);

    dfs(N,M,1,0,visited,print);


}