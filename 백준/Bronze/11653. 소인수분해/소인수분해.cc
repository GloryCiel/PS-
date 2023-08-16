#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    int i = 2;
    while(N!=1)
    {
        for(;;)
        {
            if(N%i==0)
            {
                cout<<i<<'\n';
                N/=i;
            }
            else break;
        }
        ++i;
    }
}