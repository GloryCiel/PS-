#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;cin>>n;
    vector<int>sequence(n,0);
    for(int i=0;i<n;++i)cin>>sequence[i];
    sort(sequence.begin(),sequence.end());
    int x;cin>>x;

    int left=0,right=n-1,result=0;

    while(left<right)
    {
        if(sequence[left]+sequence[right]<x)
        {
            ++left;
        }
        else
        {
            if(sequence[left]+sequence[right]==x)
            {
                result++;
                --right;
            }
            else
            {
                --right;
            }
        }
    }
    cout<<result;
}