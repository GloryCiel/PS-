#include<iostream>
using namespace std;

int main()
{
    int T;cin>>T;
    for(int i=0;i<T;++i)
    {
        int H,W,N;cin>>H>>W>>N;
        int room_number;
        int floor;
        room_number = N/H+1;
        floor = N%H;
        if(!(N%H))
        {
            room_number = N/H;
            floor = H;
        }
        cout<<floor*100+room_number<<endl;
    }
}