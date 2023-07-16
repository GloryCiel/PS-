#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    vector<int>A(N,0);vector<int>B(N,0);

    for(int i=0;i<N;++i)cin>>A[i];
    for(int i=0;i<N;++i)cin>>B[i];

    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<>());

    int sum = 0;
    for(int i=0;i<N;++i)sum+=A[i]*B[i];
    cout<<sum;
}