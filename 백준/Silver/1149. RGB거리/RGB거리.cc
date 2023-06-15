#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

int main()
{
    int N;scanf("%d",&N);
    vector<vector<int>>cost(N,vector<int>(3,0));

    int a,b,c;scanf("%d %d %d",&a,&b,&c);
    cost[0][0] = a;cost[0][1] = b;cost [0][2]=c;

    for(int i=1;i<N;++i)
    {
        int tmp1,tmp2,tmp3;scanf("%d %d %d",&tmp1,&tmp2,&tmp3);
        cost[i][0] = min(cost[i-1][1],cost[i-1][2])+tmp1;
        cost[i][1] = min(cost[i-1][0],cost[i-1][2])+tmp2;
        cost[i][2] = min(cost[i-1][0],cost[i-1][1])+tmp3;
    }

    int ans = min(cost[N-1][0],min(cost[N-1][1],cost[N-1][2]));
    printf("%d\n",ans);
}