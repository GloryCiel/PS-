#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;cin>>N>>M;
    vector<vector<int>>board(N+1,vector<int>(N+1,0));
    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=N;++j)
            cin>>board[i][j];
    }

    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=N;++j)
            board[i][j]+=board[i-1][j];
    }

    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=N;++j)
        {
            board[i][j]+=board[i][j-1];
        }
    }

    while(M--)
    {
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        cout<<board[x2][y2]-board[x1-1][y2]-board[x2][y1-1]+board[x1-1][y1-1]<<'\n';
    }


}