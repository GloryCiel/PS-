#include<iostream>

using namespace std;

int main()
{
    int T;cin>>T;

    int apt [15][15]={0,};
    for(int i=0;i<15;++i)
    {
        apt[14][i]=i+1;
    }
    for(int i=13;i>=0;--i)
    {
        int j=0;
        while(j<15)
        {
            for(int k = 0;k<=j;++k)
            {
                apt[i][j]+=apt[i+1][k];
            }
            j++;
        }
    }

    for(int a=0;a<T;++a)
    {
        int k,n;cin>>k>>n;
        cout<<apt[14-k][n-1]<<endl;
    }
}