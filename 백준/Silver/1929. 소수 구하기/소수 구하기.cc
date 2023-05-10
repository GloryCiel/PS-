#include <iostream>
#include<stdio.h>
using namespace std;

int numbers[1000001]={0};//메인함수 선언시 메모리 오버플로우

int main()
{
    int M,N;scanf("%d %d",&M,&N);
    numbers[0]=1;
    numbers[1]=1;

    for(int i=2;i<N+1;++i)
    {
        for(int j=2*i;j<N+1;j+=i)
            if(numbers[j]==0)
                numbers[j]=1;
    }

    for(int i=M;i<N+1;++i)
    {
        if(numbers[i]==0)
            printf("%d\n",i);
    }

}