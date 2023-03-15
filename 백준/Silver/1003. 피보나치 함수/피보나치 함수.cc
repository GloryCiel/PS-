#include<iostream>
using namespace std;

int memo[100]={0,1};

int a=0,b=0;

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        if(memo[n])
        {
            return memo[n];
        }
        else
        {
            return memo[n]=fibonacci(n-1) + fibonacci(n-2);
        }
    }
}

int main()
{
    int T;cin>>T;
    for(int i=0;i<T;i++)
    {
        int N;cin>>N;
        if(N==0)
            cout<<1<<" "<<0<<endl;
        else if(N==1)
            cout<<0<<" "<<1<<endl;
        else if(N==2)
        {
            cout<<1<<" "<<1<<endl;
        }
        else
        {
            cout<<fibonacci(N-1)<<" "<<fibonacci(N)<<endl;
        }
    }
}