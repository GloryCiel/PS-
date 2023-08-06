#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;

    long long int left=0,right=0,sum=0;

    vector<vector<int>>computers(N,vector<int>(N,0));

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>computers[i][j];
            sum+=computers[i][j];
            if(computers[i][j]>right)right = computers[i][j];
        }
    }

    while(left+1<right)
    {
        long long int mid = (left+right)/2;
        long long int cnt = 0;

        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                cnt+=mid>computers[i][j] ? computers[i][j]:mid;
            }
        }
        if (((double)cnt/sum)>=0.5)
            right=mid;
        else left = mid;
    }

    cout<<right;

}