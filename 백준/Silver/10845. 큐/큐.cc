#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
    int cnt;
}Queue;

void initQueue(Queue *queue)
{
    queue->front = queue->rear = NULL;
    queue->cnt = 0;
}

int empty(Queue *queue)
{
    if(queue->cnt==0)
        return 1;
    else
        return 0;
}

void push(Queue *queue,int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    if(empty(queue))
    {
        queue->front = newNode;
    }
    else
    {
        queue->rear->next=newNode;
    }
    queue->rear = newNode;
    queue->cnt++;
}

int pop(Queue *queue)
{
    int data;
    Node *ptr;
    if (empty(queue))
        return -1;
    ptr = queue->front;
    data = ptr->data;
    queue->front = ptr->next;
    free(ptr);
    queue->cnt--;

    return data;
}

int size(Queue *queue)
{
    return queue->cnt;
}

int front(Queue *queue)
{
    if(empty(queue))
        return -1;
    else
    {
        return queue->front->data;
    }
}

int back(Queue *queue)
{
    if(empty(queue))
        return -1;
    else
    {
        return queue->rear->data;
    }
}

int main()
{
    int N;
    cin>>N;
    Queue queue;
    initQueue(&queue);
    for(int i=0;i<N;i++)
    {
        string String;
        cin>>String;
        if(String=="push")
        {
            int tmp;
            cin>>tmp;
            push(&queue,tmp);
        }
        else
        {
            if(String == "pop")
                cout<<pop(&queue)<<endl;
            else if(String == "size")
                cout<<size(&queue)<<endl;
            else if(String == "empty")
                cout<<empty(&queue)<<endl;
            else if(String == "front")
                cout<<front(&queue)<<endl;
            else if(String == "back")
                cout<<back(&queue)<<endl;
        }
    }
}