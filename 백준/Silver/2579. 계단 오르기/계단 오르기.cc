#include<iostream>
#include<vector>

int max(int a,int b)
{
    return a>b?a:b;
}

using namespace std;

int main()
{
    int N;cin>>N;
    vector <int> score(N+1);
    vector <int>dp(N+1);

    for(int i=1;i<N+1;++i)
    {
        cin>>score[i];
    }

    if(N==1)
    {
        cout<<score[1]<<endl;
    }
    else if(N==2)
    {
        cout<<score[1]+score[2]<<endl;
    }
    else
    {
        dp[0]=0;
        dp[1]=score[1];
        dp[2]=score[1]+score[2];
        for(int i=3;i<N+1;++i)
        {
            dp[i]=max(dp[i-2]+score[i],dp[i-3]+score[i-1]+score[i]);
        }
        cout<<dp[N];
    }

}