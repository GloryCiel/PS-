#include <stdio.h>

void combination(n,r)
{
    unsigned long long up=1,down=1;

    if(2*r<=n)
    {
        for (int i = r; i >= 1; i--)
        {
            down = down * i;
        }

        for (int j = n; j >= n - r + 1; j--)
        {
            up = up * j;
        }
        printf("%d\n", up / down);
    }
    else
    {
        combination(n,n-r);
    }

}

int main()
{
    int test_case;
    scanf("%d",&test_case);
    for(int i=0;i<test_case;i++)
    {
        int N,M;
        scanf("%d %d",&N,&M);
        combination(M,N);
    }
}