#include<iostream>
#include<vector>

using namespace std;

long long find (long long n,long long k) {
    if (n==1LL) return 0LL;
    if (k==1LL) return n-1LL;
    if (k>n) return (find(n-1LL,k)+k)%n;
    long long cnt=n/k;
    long long res=find(n-cnt,k);
    res-=n%k;
    if (res<0LL) res+=n;
    else res+=res/(k-1LL);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;cin>>N;
    int K;cin>>K;
    cout<<find(N,K)+1;
}