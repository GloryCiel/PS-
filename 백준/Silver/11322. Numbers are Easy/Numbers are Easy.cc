#include<bits/stdc++.h>
using namespace std;

void bfs(int N,unsigned long long start)
{
    queue<long long>next;
    next.push(start);
    while(!next.empty())
    {
        long long tmp = next.front();
        if(tmp%N==0)
        {
            cout<<tmp<<'\n';
            return;
        }
        next.pop();
        string now = to_string(tmp);
        string a=now+'0',b=now+'1';
        if(a.size()<=19)
        {
            next.push(stoll(a)),next.push(stoll(b));
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;cin>>T;
    while(T--)
    {
        int N;cin>>N;
        unsigned long long start =1;
        bfs(N,start);
    }

}