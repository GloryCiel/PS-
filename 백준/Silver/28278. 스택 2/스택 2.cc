#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    stack<int>st;
    for(int i=0;i<N;++i)
    {
        int command;cin>>command;
        if(command == 1)
        {
            int tmp;cin>>tmp;
            st.push(tmp);
        }
        else if(command == 2)
        {
            if(st.empty())cout<<-1<<'\n';
            else
            {
                cout<<st.top()<<'\n';
                st.pop();
            }
        }
        else if(command == 3)
        {
            cout<<st.size()<<'\n';
        }
        else if(command == 4)
        {
            if(st.empty())cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else
        {
            if(st.empty())cout<<-1<<'\n';
            else cout<<st.top()<<'\n';
        }
    }
}