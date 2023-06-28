#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    while(cin>>N)
    {
        int a=1,b=1;
        for(;;)
        {
            if(a%N==0)
                break;
            else
            {
                b++;
                a = a*10+1;
                a%=N;
            }
        }
        cout<<b<<'\n';
    }

}