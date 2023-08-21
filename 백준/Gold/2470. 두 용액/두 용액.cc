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

    int left=0,right=n-1,result=0;
    int a=-1,b=-1,MIN=2000000002;

    while(left<right)
    {
        int now_sum = sequence[left]+sequence[right];
        if(abs(now_sum)<MIN)
        {
            MIN = abs(now_sum);
            a=sequence[left],b=sequence[right];
            if(now_sum==0)
                break;
        }
            if(now_sum<0)
            {
                left++;
            }
            else
            {
                right--;
            }
    }
    cout<<a<<' '<<b;
}