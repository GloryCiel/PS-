#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string in;getline(cin,in);

    int flag = 0;

    for(int i=0;i<in.length();++i)
    {
        if(in[i]=='U')
        {
            if(flag==0)
                flag++;
        }
        if(in[i]=='C')
        {
            if(flag==1)
                flag++;
        }
        if(in[i]=='P')
        {
            if(flag==2)
                flag++;
        }
        if(in[i]=='C')
        {
            if(flag==3)
                flag++;
        }
    }
    if(flag==4)
        cout<<"I love UCPC"<<'\n';
    else
        cout<<"I hate UCPC"<<'\n';


}