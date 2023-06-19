#include<iostream>
#include<queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;cin>>T;
    vector<bool> is_in(1000001);
    for(int repeat=0;repeat<T;++repeat)
    {
        priority_queue<pair<int,int>> max_heap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;

        int k;cin>>k;
        for(int i=0;i<k;++i)
        {
            char op;int N;cin>>op>>N;
            if(op == 'I')
            {
                max_heap.push(make_pair(N,i));
                min_heap.push(make_pair(N,i));
                is_in[i]= true;
            }
            else if(op == 'D')
            {
                if(N == -1)
                {
                    while(!min_heap.empty())
                    {
                        int tmp = min_heap.top().second;
                        if(is_in[tmp]) break;
                        min_heap.pop();
                    }
                    if(min_heap.size()>0)
                    {
                        int tmp = min_heap.top().second;
                        is_in[tmp]=false;
                    }
                }

                else
                {
                    while(!max_heap.empty())
                    {
                        int tmp = max_heap.top().second;
                        if(is_in[tmp]) break;
                        max_heap.pop();
                    }
                    if(max_heap.size()>0)
                    {
                        int tmp = max_heap.top().second;
                        is_in[tmp] = false;
                    }
                }
            }
        }
        {
            while(!min_heap.empty())
            {
                int tmp = min_heap.top().second;
                if(is_in[tmp])break;
                min_heap.pop();
            }
            while(!max_heap.empty())
            {
                int tmp = max_heap.top().second;
                if(is_in[tmp])break;
                max_heap.pop();
            }
            if(max_heap.empty() && min_heap.empty()) cout<<"EMPTY"<<'\n';
            else cout<<max_heap.top().first<<' '<<min_heap.top().first<<'\n';
        }
    }
}