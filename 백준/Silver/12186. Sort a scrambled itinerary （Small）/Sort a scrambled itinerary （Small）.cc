#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;cin>>T;
    int now = 1;
    while(T--)
    {
        int N;cin>>N;
        map<string,string>tickets;

        map<string,string>::iterator FIND;

        for(int i=0;i<N;++i)
        {
            string a,b;cin>>a>>b;
            tickets.insert(make_pair(a,b));
        }
        for(map<string,string>::iterator iter = tickets.begin();iter!=tickets.end();++iter)
        {
            int cnt=0;
            bool flag = true;
            for(map<string,string>::iterator tmp = tickets.begin();tmp!=tickets.end();++tmp)
            {
                if(iter->first == tmp->second)
                    cnt++;
            }
            if(!cnt)
            {
                FIND = iter;
                flag = false;
            }
            if(!flag) break;
        }

        string start = FIND->first;

        cout<<"Case #"<<now++<<": ";
        for(int i=0;i<N;++i)
        {
            cout<<start<<'-'<<tickets[start]<<' ';
            start = tickets[start];
        }
        cout<<'\n';
    }

}