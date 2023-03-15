#include <stdio.h>

int add(int,int);
int split(int);

int main()
{
    int initial;
    int tmp,realnext;
    int cnt=0;

    scanf("%d",&initial);

    if(initial<10)
    {
        tmp = 10*initial;
        cnt--;
    }

    else
    {
        tmp = initial;
    }
    cnt++;

    int a,b;
    a = tmp;
    b = split(tmp);

    while(1)
    {
        realnext = add(a,b);
        a = realnext;
        b = split(realnext);
        if(realnext == initial && cnt!=0)
        {
            break;
        }
        cnt++;
    }
    printf("%d",cnt);

}

int add(int a, int b)
{
    int tmp1,tmp2,new_num;
    tmp1 = a%10;
    tmp2 = b%10;

    new_num = tmp1*10+tmp2;
    return new_num;
}

int split(int a)
{
    int num;
    num = (a/10) + a%10;

    return num;
}