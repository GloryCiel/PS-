#include<bits/stdc++.h>
using namespace std;

int N,cnt=0;
void confirm(int a,int b)
{
    if(a==N)
    {
        if(b%3==0)
        {
            cnt++;
        }
        return;
    }
    confirm(a+1,b+2);
    confirm(a+1,b+1);
    confirm(a+1,b);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    confirm(1,1);
    confirm(1,2);
    cout<<cnt;

}