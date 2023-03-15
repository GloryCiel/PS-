#include<iostream>
using namespace std;

int main()
{
    int N;cin>>N;
    int i=0,j=0,cnt=1;
    for(;;)
    {
        //오른쪽 1칸 왼쪽 밑 대각선으로 끝까지 밑으로 한 칸 오른쪽 위 대각선으로 끝까지 그 다음 다시 처음 반복
        if(N==cnt)
        {
            break;
        }
        j++;
        cnt++;
        if(N==cnt)
        {
            break;
        }
        int to_stop=0;
        while(j!=0)
        {
            i++;
            j--;
            cnt++;
            if(N==cnt)
            {
                to_stop++;
                break;
            }
        }
        if(to_stop)
        {
            break;
        }
        i++;
        cnt++;
        if(N==cnt)
        {
            break;
        }
        while(i!=0)
        {
            i--;
            j++;
            cnt++;
            if(N==cnt)
            {
                to_stop++;
                break;
            }
        }
    }
    cout<<i+1<<'/'<<j+1;
}