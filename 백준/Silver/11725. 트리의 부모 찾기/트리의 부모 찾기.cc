#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> arr(100001,0);
vector<bool> visited(100001,false);
vector<int> tree[100001];

void dfs(int a)
{
    visited[a]=true;
    for(int i=0;i<tree[a].size();++i)
    {
        int next = tree[a][i];
        if(!visited[next])
        {
            arr[next]=a;
            dfs(next);
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    for(int i=0;i<N-1;++i)
    {
        int a,b;cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);

    for(int i=2;i<=N;++i)
        cout<<arr[i]<<'\n';

}