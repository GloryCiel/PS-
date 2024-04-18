#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a,b;
    while(cin>>a>>b)
    {
        int length =0;
        bool A = false;
        for(int i=0;i<b.length();++i)
        {
            if(a[length]==b[i])
                length++;
            if(length == a.length())
            {
                A=true;
                break;
            }
        }
        if(A)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

}