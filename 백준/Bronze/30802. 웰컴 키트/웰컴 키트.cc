#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;cin>>N;
    vector<int>sizes(6,0);
    for (int i=0;i<6;++i)
    {
        cin>>sizes[i];
    }
    int T,P;cin>>T>>P;

    int first_res = 0;

    for (int i=0;i<6;++i)
    {
        if (sizes[i]%T==0)
        {
            first_res+=(sizes[i]/T);
        }
        else
        {
            first_res+=(sizes[i]/T+1);
        }
    }
    int sec_res = 0,third_res = 0;

    sec_res = N/P;third_res = N%P;

    cout<<first_res<<'\n'<<sec_res<<' '<<third_res;

}