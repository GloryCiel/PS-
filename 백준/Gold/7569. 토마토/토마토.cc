#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int tomato[101][101][101];

bool range(int i,int j,int k,int H,int N,int M)
{
    if(i>=0 && i<H)
    {
        if(j>=0 && j<N)
        {
            if(k>=0 && k<M)
                return true;
        }
    }
    return false;
}

void bfs(queue<tuple<int,int,int>> &start,int H,int N,int M)
{
    int I[] = {1,-1,0,0,0,0};
    int J[] = {0,0,-1,1,0,0};
    int K[] = {0,0,0,0,1,-1};

    while(!start.empty())
    {
        int z = get<0>(start.front());//높이
        int y = get<1>(start.front());//행
        int x = get<2>(start.front());//열
        start.pop();

        for(int i=0;i<6;++i)
        {
            int next_i = z+I[i];
            int next_j = y+J[i];
            int next_k = x+K[i];
            if(range(next_i,next_j,next_k,H,N,M) && tomato[next_i][next_j][next_k]==0)
            {
                tomato[next_i][next_j][next_k] = tomato[z][y][x]+1;
                start.push(make_tuple(next_i,next_j,next_k));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M,N,H;cin>>M>>N>>H;
    queue<tuple<int,int,int>> start;

    for(int i=0;i<H;++i)
    {
        for(int j=0;j<N;++j)
        {
            for(int k=0;k<M;++k)
            {
                cin>>tomato[i][j][k];
                if(tomato[i][j][k]==1)
                    start.push(make_tuple(i,j,k));
            }
        }
    }//입력 완료

    bfs(start,H,N,M);

    int day = 0;
    for(int i=0;i<H;++i)
    {
        for(int j=0;j<N;++j)
        {
            for(int k=0;k<M;++k)
            {
                if(tomato[i][j][k]==0)
                {
                    cout<< -1<<'\n';
                    return 0;
                }
                if(day<tomato[i][j][k])
                    day = tomato[i][j][k];
            }
        }
    }

    cout<<day-1<<'\n';

}