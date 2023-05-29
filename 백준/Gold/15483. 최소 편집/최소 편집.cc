#include<iostream>
#include<algorithm>

using namespace std;

template<class T> void min(T& a, T b)
{
    if(a>b)
        a=b;
}

const int INF = 1<<29;

int main()
{
    string S,T;cin>>S>>T;

    int ** dp = new int*[S.size()+1];
    for(int i=0;i<S.size()+1;++i) dp[i]= new int[T.size()+1];
    for(int i=0;i<S.size()+1;++i)
    {
        for(int j=0;j<T.size()+1;++j)dp[i][j]=INF;
    }
    dp[0][0]=0;

    for(int i=0;i<S.size()+1;++i)
    {
        for(int j=0;j<T.size()+1;++j)
        {
            if(i>0 && j>0)
            {
                if(S[i-1]==T[j-1]) min(dp[i][j],dp[i-1][j-1]);
                else min(dp[i][j],dp[i-1][j-1]+1);
            }
            if(i>0) min(dp[i][j],dp[i-1][j]+1);
            if(j>0) min(dp[i][j],dp[i][j-1]+1);
        }
    }

    cout<<dp[S.size()][T.size()]<<endl;

}