#include<iostream>
#include<vector>

using namespace std;

string PN(long long N)
{
    char IOI[2]={'I','O'};
    string res;
    for(int i=0;i<2*N+1;++i)
    {
        if(i%2==0)
            res+=IOI[0];
        else
            res+=IOI[1];
    }
    return res;
}

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