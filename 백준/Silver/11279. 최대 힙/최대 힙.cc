#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
    priority_queue<int> max_heap;
    int N;scanf("%d",&N);
    for(int i=0;i<N;++i)
    {
        int tmp;scanf("%d",&tmp);
        if(tmp==0)
        {
            if(max_heap.empty())
                printf("%d\n",0);
            else
            {
                printf("%d\n",max_heap.top());
                max_heap.pop();
            }
        }
        else
        {
            max_heap.push(tmp);
        }
    }
}