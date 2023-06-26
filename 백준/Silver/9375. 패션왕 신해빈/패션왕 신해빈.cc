#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;cin>>T;
    while(T--)
    {
        int n;cin>>n;
        map<string,int>clothes;
        for(int i=0;i<n;++i)
        {
            string name,type;cin>>name>>type;
            if(clothes.find(type)==clothes.end())
                clothes.insert(make_pair(type,1));
            else
            {
                int tmp = clothes[type];
                clothes[type]=++tmp;
            }
        }
        vector<int>cnt(clothes.size(),0);int IT = 0;
        for(auto iter  = clothes.begin();iter != clothes.end();iter++)
        {
            cnt[IT++]=iter->second;
        }
        int result = 1;
        for(int i=0;i<cnt.size();++i)
        {
            result = result*(cnt[i]+1);
        }

        cout<<result-1<<'\n';

    }
}