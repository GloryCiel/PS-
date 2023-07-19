#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n;cin>>n;
    vector<string>raw(n);
    vector<long long>reversed(n);
    for(int i=0;i<n;++i)
    {
        cin>>raw[i];
    }

    for(int i=0;i<n;++i)
    {
        string substring;
        bool first = false;
        for(int j=raw[i].size()-1;j>=0;--j)
        {
            char tmp = raw[i][j];
            if(tmp!='0')
            {
                first=true;
                substring+=tmp;
            }
            else
            {
                if(first)
                    substring+=tmp;
            }
        }
        reversed[i]=stoull(substring);
    }
    sort(reversed.begin(),reversed.end());
    for(int i=0;i<n;++i)
        cout<<reversed[i]<<'\n';
}