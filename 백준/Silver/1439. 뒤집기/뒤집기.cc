#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;cin>>S;
    char tmp=S[0];
    int flag = 1;
    int a=0,b=0;
    for(int i=0;i<S.size();++i)
    {
        char now = S[i];
        if(now!=tmp)
        {
            tmp = now;
            if(flag==1)
            {
                flag = 0;
                a++;
            }
            else
            {
                flag = 1;
                b++;
            }
        }
    }
    if(flag==1)
    {
        flag = 0;
        a++;
    }
    else
    {
        flag = 1;
        b++;
    }
    cout<<min(a,b);
}
