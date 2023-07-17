#include<bits/stdc++.h>
using namespace std;

long long int flag=0;

void dfs(long long int number,long long int target,long long int cnt)
{
    if(number>target)
    {
        return;
    }
    if(number<target)
    {
        dfs(number*10+1,target,cnt+1);
        dfs(number*2,target,cnt+1);
    }
    if(number==target)
    {
        flag++;
        cout<<cnt+1;
        return;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int A,B;cin>>A>>B;
    dfs(A,B,0);
    if(!flag)
        cout<<-1;

}