#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
    int N,M;cin>>N>>M;
    map<string,int>hear;
    vector<string>both;
    for(int i=0;i<N;++i)
    {
        string tmp;cin>>tmp;
        hear.insert(make_pair(tmp,i));
    }
    for(int i=0;i<M;++i)
    {
        string tmp;cin>>tmp;
        if(hear.find(tmp)!=hear.end())
            both.push_back(tmp);
    }
    sort(both.begin(),both.end());
    cout<<both.size()<<endl;
    for(int i=0;i<both.size();++i)
        cout<<both[i]<<endl;
}