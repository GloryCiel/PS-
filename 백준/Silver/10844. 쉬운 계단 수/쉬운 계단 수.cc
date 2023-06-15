#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
    int N;scanf("%d",&N);
    vector<vector<long long>>length(N+1,vector<long long>(10,0));

    for(int i=1;i<10;++i)
    {
        length[1][i]=1;
    }

    for(int i=2;i<N+1;++i)
    {
        for(int j=0;j<10;++j)
        {
            if(j==0)length[i][j] = length[i-1][j+1]%1000000000;
            else if(j==9)length[i][j] = length[i-1][j-1]%1000000000;
            else
                length[i][j] = (length[i-1][j-1]+length[i-1][j+1])%1000000000;
        }
    }

    long long result = 0;
    for(int i=0;i<10;++i)
    {
        result+=length[N][i];
    }
    printf("%lld\n",result%1000000000);
}