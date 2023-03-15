#include<stdio.h>
#include<stdlib.h>

int* sequence(int);

int main()
{
    int start,end,result=0;
    scanf("%d %d",&start,&end);


    int *seq=sequence(end);
    for(int i=start-1;i<end;i++)
        result+=seq[i];
    printf("%d",result);
}

int* sequence(int end)
{
    int* result=malloc(sizeof(int)*end);
    int i=0;
    int cnt=0;
    int num=1;
    while(i<end)
    {
        result[i]=num;
        cnt++;
        if(cnt==num)
            {
                num++;
                i++;
                cnt=0;
            }
        else
            i++;
    }
    return result;
}