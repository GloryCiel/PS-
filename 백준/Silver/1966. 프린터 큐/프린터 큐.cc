#include <iostream>
using namespace std;

typedef struct queue
{
    int critical;
    int order;
    queue * next;
}queue;

queue* init(int data,int order)
{
    queue *node = new queue;
    node->critical = data;
    node->order = order;
    node->next = nullptr;
    return node;
}


int main()
{
    int T;cin>>T;
    for(int a=0;a<T;++a)
    {
        queue* head = init(-1,-1);
        int N,M;cin>>N>>M;//N은 문서개수 M은 원하는 문서 번호
        queue *cur = head;
        for(int i=0;i<N;++i)
        {
            int critical;cin>>critical;
            queue * new_node = init(critical,i);
            cur->next = new_node;
            cur = cur->next;
        }
        int cnt = 1;
        for(;;)
        {
            queue* first = head->next;
            queue* tmp = first;
            int now_critical = head->next->critical;
            bool flag = false;
            while(first->next != nullptr)
            {
                first = first->next;
                if(now_critical<first->critical)
                {
                    flag = true;
                }
            }
            if(flag)
            {
                first = tmp;
                queue* second = tmp->next;
                while(first->next!= nullptr)
                    first = first->next;
                first->next = tmp;
                head->next=second;
                tmp->next= nullptr;
            }
            else
            {
                if(head->next == nullptr)
                    break;
                else
                {
                    if(head->next->order==M)
                    {
                        cout<<cnt<<endl;
                        break;
                    }
                    else
                    {
                        cnt++;
                        queue* del = head->next;
                        head->next = del->next;
                        delete(del);
                    }
                }
            }
        }
    }
}