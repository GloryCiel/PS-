#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool comp(string a, string b)
{
    if(a==b) return false;

    string A=a+b;
    string B=b+a;
    if(A>B)return true;
    else return false;
}

int main()
{
    int N;cin>>N;

    vector<string>number;
    bool is_0=true;

    for(int i=0;i<N;++i)
    {
        string tmp;cin>>tmp;
        if(tmp!="0" &&is_0)
            is_0=false;
        number.push_back(tmp);
    }
    if(is_0)
        cout<<0;
    else
    {
        sort(number.begin(),number.end(),comp);
        for(int i=0;i<number.size();++i)
            cout<<number[i];
    }

}