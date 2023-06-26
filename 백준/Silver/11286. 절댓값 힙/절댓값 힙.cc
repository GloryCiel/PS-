#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare
{
    bool operator()(int a,int b)
    {
        if(abs(a)==abs(b))
            return a>b;
        return abs(a)>abs(b);
    }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    priority_queue<int,vector<int>,compare> Q;
    for(int i=0;i<N;++i)
    {
        int x;cin>>x;
        if(Q.empty() && !x)
            cout<<0<<'\n';
        else if(!Q.empty() && !x)
        {
            cout<<Q.top()<<'\n';
            Q.pop();
        }
        else if(x)
        {
            Q.emplace(x);
        }
    }

}