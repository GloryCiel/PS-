#include <iostream>
using namespace std;

int main()
{
    int a[10000]={0};
    int j=0;
    int N,K;cin>>N>>K;
    for(int i=1;i<=N;++i)
    {
        if(!(N%i))
        {
            a[j++]=i;
        }
    }
    cout<<a[K-1]<<endl;
}