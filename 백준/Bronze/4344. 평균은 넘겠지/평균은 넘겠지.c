#include <stdio.h>
#include <stdlib.h>

double Return_mean(int*,int);

int main()
{
    int test_case;
    scanf("%d\n",&test_case);

    for(int i=0;i<test_case;i++)
    {
        int num;
        scanf("%d ",&num);
        int *arr = malloc(sizeof(int)*num);
        for(int i=0;i<num;i++)
        {
            int tmp;
            scanf("%d ",&tmp);
            arr[i]=tmp;
        }
        double mean = Return_mean(arr,num);
        double over_mean=0;

        for(int i=0;i<num;i++)
        {
            if(arr[i]>mean)
            {
                over_mean+=1;
            }
        }
        printf("%.03f\%\n",over_mean/num*100);
        free(arr);
    }
}

double Return_mean(int *arr,int n)
{
    int add=0;
    
    for(int i=0;i<n;i++)
    {
        add+=arr[i];
    }

    double result = add/n;

    return result;
}