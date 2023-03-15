#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int N;cin>>N;
    int answer = 0;
    for(int i=0;i<N;++i)
    {
        string now;cin>>now;
        int words[26]={0};
        int last_alphabet=now.at(0)-97;
        words[last_alphabet]=1;
        int cnt=0;
        for(int j=1;j<now.length();++j)
        {
            if(now.at(j)-97!=last_alphabet)
            {
                if(words[now.at(j)-97]==1)
                {
                    cnt++;
                    break;
                }
                else
                {
                    last_alphabet = now.at(j)-97;
                    words[last_alphabet]=1;
                }
            }
        }
        if(!cnt)
            answer++;
    }
    cout<<answer;
}