#include <iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    for(int i=0;i<N;++i)
    {
        int tmp;cin>>tmp;
        if(max_heap.empty())
            max_heap.push(tmp);
        else if(max_heap.size()==min_heap.size())
            max_heap.push(tmp);
        else
            min_heap.push(tmp);

        if(!max_heap.empty() && !min_heap.empty() && (max_heap.top()>min_heap.top()))
        {
            int tmp1 = max_heap.top();
            int tmp2 = min_heap.top();

            max_heap.pop();min_heap.pop();
            max_heap.push(tmp2);min_heap.push(tmp1);
        }
        cout<<max_heap.top()<<'\n';
    }
}