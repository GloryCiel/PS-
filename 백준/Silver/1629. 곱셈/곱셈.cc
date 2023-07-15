#include<bits/stdc++.h>
using namespace std;

long long res(long long A,long long B,long long C)
{
    long long result = 1;
    while(B>0)
    {
        if(B%2!=0)result=(result*A)%C;
        B=B/2;
        A=(A*A)%C;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A,B,C;cin>>A>>B>>C;

    cout<<res(A,B,C);

}