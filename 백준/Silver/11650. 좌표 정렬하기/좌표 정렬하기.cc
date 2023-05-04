#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct
{
    int x;
    int y;
}axis;

bool compare(const axis& A,const axis& B)
{
    if(A.x!=B.x)
    {
        return(A.x<B.x);
    }
    else
    {
        return(A.y<B.y);
    }
}

int main()
{
    int N;scanf("%d",&N);
    axis * Axis = new axis[N];
    for(int i=0;i<N;++i)
    {
        int x,y;scanf("%d %d",&x,&y);
        Axis[i].x=x;
        Axis[i].y=y;
    }
    sort(Axis,Axis+N, compare);
    for(int i=0;i<N;++i)
    {
        printf("%d %d\n",Axis[i].x,Axis[i].y);
    }
}