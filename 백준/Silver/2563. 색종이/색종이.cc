#include <iostream>
using namespace std;

int main()
{
    int arr[101][101]={0};
    int N;cin>>N;
    int ans=0;
    for(int i=0;i<N;++i)
    {
        int a,b;cin>>a>>b;
        for(int j=100-b-10;j<100-b;++j)
        {
            for(int k=a;k<a+10;++k)
                arr[j][k]=1;
        }
    }
    for(int i=0;i<101;++i)
        for(int j=0;j<101;++j)
        {
            if(arr[i][j]==1)
                ans++;
        }
    cout<<ans<<endl;
}