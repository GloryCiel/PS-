#include<iostream>

using namespace std;

int main()
{
    int N,M,B;cin>>N>>M>>B;//세로,가로,가진 블럭
    int B_tmp=B;
    int **land = new int*[N];
    for(int i=0;i<N;++i)
    {
        land[i]=new int[M];
    }
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<M;++j)
            cin>>land[i][j];
    }//입력 끝

    int result_time,result_height;
    bool first =true;

    for(int h=0;h<=256;++h)
    {
        int time = 0;
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<M;++j)
            {
                if(land[i][j]>h)
                {
                    time=time + (land[i][j]-h)*2;
                    B = B+(land[i][j]-h);
                }
                else if(land[i][j]<h)
                {
                    time = time + (h-land[i][j]);
                    B=B-(h-land[i][j]);
                }
            }
        }
        if(B>=0)
        {
            if(first)
            {
                first = false;
                result_time = time;
                result_height = h;
            }
            else
            {
                if(time<=result_time)
                {
                    result_time = time;
                    result_height = h;
                }
            }
        }
        B=B_tmp;
    }

    cout<<result_time<<' '<<result_height<<endl;

}