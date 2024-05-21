#include <bits/stdc++.h>

using namespace std;


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;cin>>N;
    vector<int>price(N,0);
    for(int i=0;i<N;++i)cin>>price[i];
    int MAX=-1;
    int res=0;
    for(int i=N-1;i>=0;--i)
    {
        if(MAX<price[i])
            MAX=price[i];
        res=max(res,MAX-price[i]);
    }
    cout<<res;

}