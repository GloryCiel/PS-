#include<iostream>

using namespace std;

int main()
{
    int N,S;string M;cin>>N>>S>>M;
    int res = 0;
    for(int i=1;i<M.size();++i)
    {
        int cnt = 0;
        if(M[i-1]=='I')
        {
            while(M[i]=='O' && M[i+1]=='I')
            {
                i+=2;
                cnt++;
                if(cnt==N)
                {
                    cnt--;
                    res++;
                }
            }
        }
    }
    cout<<res<<'\n';
}