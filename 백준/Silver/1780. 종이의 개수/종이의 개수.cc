#include <bits/stdc++.h>

using namespace std;

int zero_cnt=0;
int one_cnt=0;
int minus_one_cnt=0;

bool is_Same(int**,int,int,int);
void div_conquer(int**,int,int,int);

int main()
{
    int N;
    cin >> N;
    //vector <vector<int>> paper(N, vector<int>(N, 0));
    int ** paper = (int **)malloc(sizeof(int*)*N);
    for(int i=0;i<N;++i)
    {
        paper[i]=(int *)malloc(sizeof(int)*N);
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> paper[i][j];
        }
    }
    div_conquer(paper,N,0,0);

    cout<<minus_one_cnt<<'\n'<<zero_cnt<<'\n'<<one_cnt<<'\n';

}

void div_conquer(int **paper, int N,int init_i,int init_j)
{
    if(is_Same(paper,init_i,init_j,N))
    {
        int tmp = paper[init_i][init_j];
        if(tmp ==-1)minus_one_cnt++;
        else if(tmp==0)zero_cnt++;
        else one_cnt++;
    }
    else
    {
        div_conquer(paper,N/3,init_i,init_j);
        div_conquer(paper,N/3,init_i,init_j+N/3);
        div_conquer(paper,N/3,init_i,init_j+2*N/3);
        div_conquer(paper,N/3,init_i+N/3,init_j);
        div_conquer(paper,N/3,init_i+N/3,init_j+N/3);
        div_conquer(paper,N/3,init_i+N/3,init_j+2*N/3);
        div_conquer(paper,N/3,init_i+2*N/3,init_j);
        div_conquer(paper,N/3,init_i+2*N/3,init_j+N/3);
        div_conquer(paper,N/3,init_i+2*N/3,init_j+2*N/3);
    }
}

bool is_Same(int **paper,int init_i, int init_j,int N)
{
    int start = paper[init_i][init_j];
    for(int i=init_i;i<init_i+N;++i)
    {
        for(int j=init_j;j<N+init_j;++j)
        {
            if(paper[i][j]!=start)
                return false;
        }
    }
    return true;
}
