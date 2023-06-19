#include<iostream>
#include<map>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string,string> site_password;

    int N,M;cin>>N>>M;
    for(int i=0;i<N;++i)
    {
        string tmp1,tmp2;cin>>tmp1>>tmp2;
        site_password.insert(make_pair(tmp1,tmp2));
    }

    for(int i=0;i<M;++i)
    {
        string tmp;cin>>tmp;
        cout<<site_password[tmp]<<'\n';
    }
}