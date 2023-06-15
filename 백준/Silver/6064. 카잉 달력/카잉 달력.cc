#include<iostream>
#include<stdio.h>

using namespace std;

int order(int M,int N,int x,int y)
{

}

int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        int M,N,x,y;scanf("%d %d %d %d",&M,&N,&x,&y);
        x-=1;y-=1;
        bool flag = false;
        for(int j=x;j<N*M;j+=M)
        {
            if(j%N == y)
            {
                printf("%d\n",j+1);
                flag = true;
                break;
            }
        }
        if(!flag)printf("%d\n",-1);
    }
}