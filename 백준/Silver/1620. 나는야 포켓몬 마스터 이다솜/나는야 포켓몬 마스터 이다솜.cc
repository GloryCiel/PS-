#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;cin>>N>>M;
    map<string,int>pokemon;
    map<int,string>pokemon_num;
    for(int i=0;i<N;++i)
    {
        string tmp;cin>>tmp;
        pokemon.insert(make_pair(tmp,i+1));
        pokemon_num.insert(make_pair(i+1,tmp));
    }
    for(int i=0;i<M;++i)
    {
        string tmp;cin>>tmp;
        if(tmp[0]<='9'&&tmp[0]>=0)
        {
            cout<<pokemon_num.find(stoi(tmp))->second<<'\n';
        }
        else
        {
            cout<<pokemon.find(tmp)->second<<'\n';
        }
    }
}