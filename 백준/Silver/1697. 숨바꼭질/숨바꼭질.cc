#include<iostream>
#include <queue>

using namespace std;

void bfs(int N,int K,bool* visit)
{
    queue<pair<int, int>> Queue;
    Queue.push(make_pair(N,0));
    while(!Queue.empty())
    {
        int now = Queue.front().first;
        int time = Queue.front().second;
        Queue.pop();
        if(now==K)
        {
            cout<<time;
            break;
        }
        if(now+1>=0 && now+1<100001)
        {
            if(!visit[now+1])
            {
                visit[now+1]=true;
                Queue.push(make_pair(now+1,1+time));
            }
        }
        if(now-1>=0 && now-1<100001)
        {
            if(!visit[now-1])
            {
                visit[now-1]=true;
                Queue.push(make_pair(now-1,1+time));
            }
        }
        if(now*2>=0 && now*2<100001)
        {
            if(!visit[2*now])
            {
                visit[now*2]=true;
                Queue.push(make_pair(now*2,1+time));
            }
        }
    }
}

int main()
{
    int N,K;cin>>N>>K;
    bool visit[100001]={false};
    visit[N]=true;
    bfs(N,K,visit);
}