#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    vector<int>friends[N];

    for(int i=0;i<N;++i)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < tmp.size(); ++j)
        {
            if (tmp[j] == 'Y')
                friends[i].push_back(j);
        }
    }

    int Max = 0;
    for(int i=0;i<N;++i)
    {
        vector<bool>visited(N,false);
        vector<int>to_visit;
        visited[i]=true;
        int Friend = 0;
        if(friends[i].empty()) continue;
        for(int j=0;j<friends[i].size();++j)
        {
            int now = friends[i][j];
            Friend++;
            to_visit.push_back(now);
            visited[now]=true;
        }

        for(int j=0;j<to_visit.size();++j)
        {
            for(int k=0;k<friends[to_visit[j]].size();++k)
            {
                if(!visited[friends[to_visit[j]][k]])
                {
                    Friend++;
                    visited[friends[to_visit[j]][k]]=true;
                }
            }
        }
        Max = max(Max,Friend);

    }
    cout<<Max;

}