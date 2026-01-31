#include <bits/stdc++.h>


using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M; cin>>N>>M;
    vector<int>array(N);
    vector<int>subarray(N);
    for (int i=0;i<N;++i)
    {
        cin>>array[i];
        if (i==0) subarray[i]=array[i];
        else subarray[i]=subarray[i-1]+array[i];
    }
    for (int i=0;i<M;++i)
    {
        int a,b;cin>>a>>b;a--;b--;
        if (a==0)cout<<subarray[b]<<'\n';
        else if (a==b)cout<<array[a]<<'\n';
        else cout<<subarray[b]-subarray[a-1]<<'\n';

    }


}