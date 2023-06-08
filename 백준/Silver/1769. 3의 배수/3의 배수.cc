#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string X;cin>>X;
    int tmp = 0;
    int cnt=0;
    while(X.size()!=1)
    {
        for(int i=0;i<X.size();++i)
        {
            tmp+=(int)X[i]-48;
        }
        X=to_string(tmp);
        cnt++;
        tmp=0;
    }
    if(stoi(X)%3==0)
    {
        cout<<cnt<<'\n'<<"YES"<<'\n';
    }
    else
    {
        cout<<cnt<<'\n'<<"NO"<<'\n';
    }

}