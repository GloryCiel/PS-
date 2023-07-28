#include<bits/stdc++.h>
using namespace std;

void next(vector<int>numbers,vector<int>&arr,int num,int len,int N,int M)
{
    if(len == M)
    {
        for(int i=0;i<M;++i)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }

    int final = 0;

    for(int i=num;i<N;++i)
    {
        if(numbers[i]!=final)
        {
            arr[len]=numbers[i];
            final = arr[len];
            next(numbers,arr,i,len+1,N,M);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;cin>>N>>M;
    vector<int>numbers(N,0);
    vector<int>arr(N,0);
    for(int i=0;i<N;++i)
    {
        cin>>numbers[i];
    }
    sort(numbers.begin(),numbers.end());

    next(numbers,arr,0,0,N,M);
}