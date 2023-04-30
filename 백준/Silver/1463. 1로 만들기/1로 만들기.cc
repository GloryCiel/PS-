#include<iostream>
using namespace std;

int choose_min(int, int);

int main()
{
    int N;
    cin>>N;
    int* dp = new int[N+1];
    for(int i=0;i<N+1;++i)
        dp[i]=0;

    for(int i=2;i<N+1;i++)
    {
        dp[i]=dp[i-1]+1;
        if(i%3==0)
        {
            dp[i] = choose_min(dp[i],dp[i/3]+1);
        }
        if(i%2==0)
        {
            dp[i] = choose_min(dp[i],dp[i/2]+1);
        }
    }
    cout<<dp[N];
    free(dp);
}

int choose_min(int a, int b)
{
    if(a<=b)
        return a;
    else
        return b;
}