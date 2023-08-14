#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

//void quickSort(int *, int, int);

int main()
{
    int N;scanf("%d",&N);
    int *arr = new int[N];
    for(int i=0;i<N;++i)
    {
        scanf("%d",&arr[i]);
    }

    sort(arr,arr+N);

    for(int i=0;i<N;++i)
    {
        printf("%d\n",arr[i]);
    }

    delete[] arr;
}

/*void quickSort(int *array,int begin, int end)
{
    if(begin >=end)
        return;
    int pivot = begin;
    int i = pivot+1;
    int j = end;
    int tmp;

    while(i<=j)
    {
        while(i<=end && array[i]<=array[pivot])
            i++;
        
        while(j>begin && array[j]>=array[pivot])
            j--;
        if(i>j)
        {
            tmp =array[j];
            array[j]=array[pivot];
            array[pivot]=tmp;
        }
        else
        {
            tmp = array[i];
            array[i]=array[j];
            array[j]=tmp;
        }
    }
    quickSort(array,begin,j-1);
    quickSort(array,j+1,end);
}*/