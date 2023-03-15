#include<iostream>
using namespace std;

int main()
{
    int N;cin>>N;
    if(N==1)
        cout<<1;
    else
    {
        int a =6;
        int n=2;
        for(;;)
        {
            int stop = 0;
            for(int i=0;i<a;++i)
            {
                if(n==N)
                {
                    stop++;
                    break;
                }
                n++;
            }
            if(stop)
            {
                break;
            }
            else
            {
                a+=6;
            }
        }
        cout<<a/6+1;
    }
}