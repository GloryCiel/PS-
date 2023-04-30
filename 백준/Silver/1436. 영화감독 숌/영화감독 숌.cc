#include<iostream>
using namespace std;

int main()
{
    int first=666;
    int cnt=0;
    int tmp;
    int n;cin>>n;

    for(;;)
    {
        tmp = first;
        do
        {
            if(tmp%1000==666)
            {
                cnt++;
                break;
            }
            tmp/=10;
        }while(tmp>0);

        if(cnt==n)
        {
            cout<<first<<endl;
            break;
        }
        
        first++;
    }
}