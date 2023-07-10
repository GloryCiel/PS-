#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;cin>>N>>M;
    vector<int>board(101,0);
    for(int i=0;i<N;++i)
    {
        int tmp1,tmp2;cin>>tmp1>>tmp2;
        board[tmp1]=tmp2;
    }

    for(int i=0;i<M;++i)
    {
        int tmp1,tmp2;cin>>tmp1>>tmp2;
        board[tmp1]=tmp2;
    }

    queue<pair<int,int>>can_go;
    vector<bool>visited(101,false);
    can_go.push(make_pair(1,0));
    visited[1]=true;
    bool flag = false;
    while(!can_go.empty())
    {
        if(flag)
            break;
        int now = can_go.front().first;
        int cnt = can_go.front().second;
        can_go.pop();

        for(int i=1;i<=6;++i)
        {
            int next = now+i;
            if(next==100)
            {
                cout<<++cnt;
                flag = true;
                break;
            }
            else if(next<100)
            {
                while(board[next]!=0)
                {
                    next = board[next];
                }
                if(!visited[next])
                {
                    can_go.push(make_pair(next,cnt+1));
                    visited[next]=true;
                }
            }
        }
    }
}