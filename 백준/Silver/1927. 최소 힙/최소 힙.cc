#include <iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int,vector<int>,greater<>> min_heap;

    int N;cin>>N;
    for(int i=0;i<N;++i)
    {
        int x;cin>>x;

        if(x==0)
        {
            if(!min_heap.empty())
            {
                cout<<min_heap.top()<<'\n';
                min_heap.pop();
            }

            else
                cout<<0<<'\n';

        }

        else
        {
            min_heap.push(x);
        }
    }

}