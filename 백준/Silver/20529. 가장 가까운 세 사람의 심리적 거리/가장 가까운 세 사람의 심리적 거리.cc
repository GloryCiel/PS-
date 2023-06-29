#include<bits/stdc++.h>

using namespace std;

int distance(string tmp1,string tmp2,string tmp3)
{
    int result = 0;
    for(int i=0;i<4;++i)
    {
        if(tmp1[i]!=tmp2[i])
            result++;
    }

    for(int i=0;i<4;++i)
    {
        if(tmp3[i]!=tmp2[i])
            result++;
    }

    for(int i=0;i<4;++i)
    {
        if(tmp1[i]!=tmp3[i])
            result++;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;cin>>T;
    while(T--)
    {
        int N;cin>>N;
        vector<string>mbti(N);
        for(int i=0;i<N;++i)
            cin>>mbti[i];

        if(N>32)
        {
            cout<<0<<'\n';
        }
        else
        {
            int min =100;
            for(int i=0;i<N-2;++i)
            {
                for(int j=i+1;j<N-1;++j)
                {
                    for(int k=j+1;k<N;++k)
                    {
                        int tmp = distance(mbti[i],mbti[j],mbti[k]);
                        if(tmp<min)
                            min = tmp;
                    }
                }
            }
            cout<<min<<'\n';
        }
    }

}