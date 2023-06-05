#include<iostream>
#include<stdio.h>
#define MIN(a,b) (a<b ? a: b)

using namespace std;

void result(string,int *,int *,int);

int main()
{
    int btn[10]={1,1,1,1,1,1,1,1,1,1};
    int min = 0x3f3f3f3f;
    int N,M;
    scanf("%d %d",&N,&M);
    min = MIN(min,abs(100-N));

    for(int i=0;i<M;++i)
    {
        int tmp;cin>>tmp;
        btn[tmp]=0;
    }
    if(M<10)
        result("",btn,&min,N);

    printf("%d",min);

}

void result(string num,int * btn,int *min,int N)
{
    for(int i=0;i<10;++i)
    {
        if(btn[i])
        {
            string num_tmp = num+to_string(i);
            *min = MIN(*min,abs(N-stoi(num_tmp))+num_tmp.length());

            if(num_tmp.length()<6)result(num_tmp,btn,min,N);

        }
    }
}