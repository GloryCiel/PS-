#include<bits/stdc++.h>
using namespace std;

vector<int>is_prime(246913,true);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    is_prime[0]=false,is_prime[1]=false;
    for(int i=2;i<sqrt(246913);++i)
    {
        if(is_prime[i])
        {
            for(int j=2*i;j<=246913;j+=i)
                is_prime[j]=false;
        }
    }

    for(;;)
    {
        int n;cin>>n;
        int cnt = 0;
        if(n==0)
            return 0;

        for(int i=n+1;i<=2*n;++i)
        {
            if(is_prime[i])cnt++;
        }
        cout<<cnt<<'\n';
    }
}
