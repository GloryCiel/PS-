#include<iostream>
using namespace std;

typedef struct NODE
{
    int data;
    NODE* next;
}NODE;

void push(NODE* init,int Data)
{
    NODE * new_node = new NODE;
    new_node->data=Data;
    new_node->next=NULL;
    if(init->next==NULL)
    {
        init->next = new_node;
        return;
    }
    NODE *tmp = init->next;
    init->next = new_node;
    new_node->next = tmp;
}

void pop(NODE * init)
{
    if(init->next==NULL)
    {
        cout << -1 << endl;
        return;
    }
    NODE *tmp = init->next->next;
    cout<<init->next->data<<endl;
    init->next = tmp;
}

int main()
{
    NODE init;init.next = NULL;
    int N;cin>>N;
    int size = 0;
    for(int i=0;i<N;++i)
    {
        string tmp1;cin>>tmp1;
        if(tmp1 == "push")
        {
            int tmp2;cin>>tmp2;
            push(&init,tmp2);
            size++;
        }
        else if(tmp1 == "pop")
        {
            pop(&init);
            if(size!=0)
                size--;
        }
        else if(tmp1 =="size")
        {
            cout<<size<<endl;
        }
        else if(tmp1 =="empty")
        {
            if(init.next==NULL)
                cout<<1<<endl;
            else
                cout<<0<<endl;
        }
        else if(tmp1 == "top")
        {
            if(init.next==NULL)
                cout<<-1<<endl;
            else
                cout<<init.next->data<<endl;
        }
    }
}