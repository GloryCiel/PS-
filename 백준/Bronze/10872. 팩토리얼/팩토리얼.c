#include <stdio.h>

int factorial(int a)
{
    if(a==1 || a==0)
        return 1;
    return a* factorial(a-1);
}

int main()
{
    int a;
    scanf("%d",&a);
    int b =factorial(a);
    printf("%d",b);
}