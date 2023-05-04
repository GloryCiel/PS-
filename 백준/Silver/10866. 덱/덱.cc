#include<iostream>
using namespace std;

typedef struct NODE
{
    int data;
    NODE* next;
}NODE;

NODE* init();
void push_front(NODE*,int);
void push_back(NODE*, int);
void pop_front(NODE*);
void pop_back(NODE*);
void size(NODE*);
void empty(NODE*);
void front(NODE*);
void back(NODE*);


int main()
{
    int N;cin>>N;
    NODE* head = init();
    for(int i=0;i<N;++i)
    {
        string tmp1;cin>>tmp1;
        if(tmp1 == "push_front")
        {
            int tmp2;cin>>tmp2;
            push_front(head,tmp2);
        }
        else if(tmp1 == "push_back")
        {
            int tmp2;cin>>tmp2;
            push_back(head,tmp2);
        }
        else if(tmp1 == "pop_front")
        {
            pop_front(head);
        }
        else if(tmp1 =="pop_back")
        {
            pop_back(head);
        }
        else if(tmp1 == "size")
        {
            size(head);
        }
        else if(tmp1 =="empty")
        {
            empty(head);
        }
        else if(tmp1 =="front")
        {
            front(head);
        }
        else
        {
            back(head);
        }
    }
}

NODE* init()
{
    NODE* head = new NODE();
    head->next =NULL;
    return head;
}

void push_front(NODE* head, int number)
{
    NODE * new_node = init();
    new_node->next = NULL;
    new_node->data = number;
    if(head->next==NULL)
    {
        head->next = new_node;
        return;
    }
    NODE* tmp = head->next;
    head->next = new_node;
    new_node->next = tmp;
}

void push_back(NODE* head, int number)
{
    NODE* new_node = init();
    new_node->next = NULL;
    new_node->data = number;//새로운 노드 생성

    NODE* cur = head;
    if(head->next==NULL)
    {
        head->next = new_node;
        return;
    }
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = new_node;
}

void pop_front(NODE* head)
{
    if(head->next==NULL)
    {
        cout<<-1<<endl;
        return;
    }
    NODE* tmp = head->next->next;
    cout<<head->next->data<<endl;
    head->next = tmp;
}

void pop_back(NODE* head)
{
    if(head->next == NULL)
    {
        cout<<-1<<endl;
        return;
    }
    NODE* cur = head;
    while(cur->next->next!=NULL)
        cur=cur->next;
    NODE * tmp = cur->next;
    cout<<tmp->data<<endl;
    cur->next=NULL;
    delete(tmp);
}

void size(NODE* head)
{
    int size = 0;
    NODE* cur = head;
    while(cur->next!=NULL)
    {
        size++;
        cur = cur->next;
    }
    cout<<size<<endl;
}

void empty(NODE* head)
{
    if(head->next==NULL)
        cout<<1<<endl;
    else
        cout<<0<<endl;
}

void front(NODE* head)
{
    if(head->next==NULL)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<head->next->data<<endl;
}

void back(NODE* head)
{
    if(head->next==NULL)
    {
        cout<<-1<<endl;
        return;
    }
    NODE * cur = head;
    while(cur->next!=NULL)
        cur=cur->next;
    cout<<cur->data<<endl;
}