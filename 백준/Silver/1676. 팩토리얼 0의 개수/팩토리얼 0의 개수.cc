#include<iostream>

using namespace std;

int main()
{
    int N;cin>>N;
    int num_2=0,num_5=0;
    for(int i=1;i<=N;++i)
    {
        if(i%2==0)
        {
            int tmp = i;
            while(tmp%2==0)
            {
                num_2++;
                tmp/=2;
            }
        }
        if(i%5==0)
        {
            int tmp = i;
            while(tmp%5==0)
            {
                num_5++;
                tmp/=5;
            }
        }
    }
    if(num_2<num_5)
        cout<<num_2;
    else
    {
        cout<<num_5;
    }
}