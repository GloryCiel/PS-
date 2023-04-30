#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
    int N;scanf("%d",&N);
    int * card = new int[N];
    for(int i=0;i<N;++i)
    {
        scanf("%d",&card[i]);
    }
    int M;scanf("%d",&M);
    int * find = new int[M];
    for(int i=0;i<M;++i)
    {
        scanf("%d",&find[i]);
    }
    sort(card,card+N);
    for(int i=0;i<M;++i)
    {
        cout<<upper_bound(card,card+N,find[i]) - lower_bound(card,card+N,find[i])<<" ";
    }
}