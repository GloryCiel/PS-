#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string, string);

int main()
{
    int N;cin>>N;
    string* words = new string[N];
    for(int i=0;i<N;++i)
    {
        cin>>words[i];
    }
    sort(words,words+N, compare);
    for(int i=0;i<N;++i)
    {
        if(words[i]==words[i+1] && i+1<N)
            continue;
        else
            cout<<words[i]<<endl;
    }

}

bool compare(string a, string b)
{
    if(a.length()!=b.length())
    {
        return a.length()<b.length();//a가 b보다 짧아야 true
    }
    else
    {
        return a<b;//사전순인지 true/false
    }
}