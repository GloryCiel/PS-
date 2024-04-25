#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;cin>>n;

    vector<int>arr(n,0);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    sort(arr.begin(),arr.end());

    for(int i=n-1;i>=0;--i)
        cout<<arr[i]<<'\n';
}