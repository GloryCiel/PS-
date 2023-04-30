#include <iostream>
using namespace std;
#define small(a,b) ((a<b)?a:b)

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};

string BB[8]={
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int WB_cnt(string*,int,int);
int BB_cnt(string*,int,int);

int main()
{
    int N,M;cin>>N>>M;
    string* board = new string[N];
    for(int i=0;i<N;++i)
    {
        cin>>board[i];
    }
    int min =100000000;
    for(int i=0;i<N-7;++i)
    {
        for(int j=0;j<M-7;++j)
        {
            int tmp = small(WB_cnt(board,i,j), BB_cnt(board,i,j));
            if(tmp<min)
                min = tmp;
        }
    }
    cout<<min<<endl;
}

int WB_cnt(string* a,int x,int y)
{
    int result=0;
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(a[i+x][j+y]!=WB[i][j])
                result++;
        }
    }
    return result;
}

int BB_cnt(string* a,int x, int y)
{
    int result=0;
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(a[i+x][j+y]!=BB[i][j])
                result++;
        }
    }
    return result;
}