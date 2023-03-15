#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int N;cin>>N;
    int *arr = new int[N];
    for(int i=0;i<N;++i)
    {
        cin>>arr[i];
    }

    sort(arr,arr+N);

    int M;cin>>M;

    for(int i=0;i<M;++i)
    {
        int tmp;cin>>tmp;
        cout<<binary_search(arr,arr+N,tmp)<<'\n';
    }
}