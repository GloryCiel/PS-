#include <bits/stdc++.h>
#define alloc 10001

using namespace std;

int V,E, e1, e2, cnt, SCC_num;
int numbering[alloc];
int scc_numbering[alloc];
vector<int>graph[alloc];
vector<vector<int>>SCC;
stack<int> sta;
bool finished[alloc];

int dfs(int);

int main()
{
    cin>>V>>E;

    for(int i=0;i<E;++i)
    {
        cin>>e1>>e2;
        graph[e1].push_back(e2);
    }
    for(int i=0;i<V;++i)
    {
        if(numbering[i+1]==0)dfs(i+1);
    }
    sort(SCC.begin(),SCC.end());

    cout<<SCC_num<<'\n';
    for(int i=0;i<SCC.size();++i)
    {
        for(int j=0;j<SCC[i].size();++j)
        {
            cout<<SCC[i][j]<<" ";
        }
        cout<<"-1\n";
    }
}

int dfs(int num)
{
    numbering[num]=++cnt;
    sta.push(num);

    int result = numbering[num];
    for(int i:graph[num])
    {
        if(numbering[i]==0)result = min(result,dfs(i));
        else if(!finished[i])result = min(result, numbering[i]);
    }
    if(result == numbering[num])
    {
        vector<int>tmp;
        while(true)
        {
            int t = sta.top();
            sta.pop();
            tmp.push_back(t);
            finished[t]=true;
            scc_numbering[t]=SCC_num;
            if(t==num)break;
        }
        sort(tmp.begin(), tmp.end());
        SCC.push_back(tmp);
        SCC_num++;
    }
    return result;
}