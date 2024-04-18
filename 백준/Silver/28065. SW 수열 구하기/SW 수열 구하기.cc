#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;cin>>N;

    /*vector<int>a(N,0);
    vector<int>b(N,0);*/
    int * a = (int *)malloc(sizeof(int)*N);
    int * b = (int *)malloc(sizeof(int)*N);

    for(int i=0;i<N;++i)
    {
        a[i]=i+1;
    }
    int i=0,j=N-1,idx=0;
    while(j>=i)
    {
        b[idx++]=a[j--];
        if(j>i)
            b[idx++]=a[i++];
        else
            b[idx]=a[j];
    }
    for(int c= 0;c<N;++c)
        cout<<b[c]<<' ';

}