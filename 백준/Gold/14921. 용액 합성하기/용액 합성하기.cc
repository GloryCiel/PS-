#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;cin>>N;
    vector<int>characteristic(N,0);
    for(int i=0;i<N;++i)cin>>characteristic[i];

    int l=0,r=N-1;
    int mix = 2000000000;
    while(l!=r)
    {
        if(characteristic[l]+characteristic[r]>0)
        {
            if(abs(characteristic[l]+characteristic[r])<abs(mix))
                mix = characteristic[l]+characteristic[r];
            r--;
        }
        else if(characteristic[l]+characteristic[r]<0)
        {
            if(abs(characteristic[l]+characteristic[r])<abs(mix))
                mix = characteristic[l]+characteristic[r];
            l++;
        }
        else
        {
            cout<<0<<'\n';
            return 0;
        }
    }
    cout<<mix<<'\n';
    return 0;

}