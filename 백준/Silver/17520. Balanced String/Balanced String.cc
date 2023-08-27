#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;cin>>n;

    int res = 1;
    if(n%2!=0)n++;

    for(int i=0;i<n/2;++i)
    {
        res=(res*2)%16769023;
    }

    cout<<res;

}