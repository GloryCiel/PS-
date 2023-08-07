#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long min,max;cin>>min>>max;
    long long res = max-min+1;

    vector<bool>arr(res,false);

    long long start = 2;

    while(start*start<=max)
    {
        long long tmp = min/(start*start);
        if(min%(start*start)!=0)tmp+=1;

        while(tmp*start*start<=max)
        {
            if(!arr[tmp*start*start-min])
            {
                arr[tmp*start*start-min]=true;
                res-=1;
            }
            tmp++;
        }
        start++;
    }

    cout<<res;

}