#include<bits/stdc++.h>
using namespace std;

int op(char a)
{
    if(a=='+'||a=='-')
        return 1;
    if(a=='*' || a=='/')
        return 2;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string in_order;cin>>in_order;
    stack<char>tmp;
    string print;

    for(int i=0;i<in_order.size();++i)
    {
        if(in_order[i]=='(') tmp.push('(');
        else if(in_order[i]==')')
        {
            while(tmp.top()!='(')
            {
                print+=tmp.top();
                tmp.pop();
            }
            tmp.pop();//(pop해야함
        }
        else
        {
            if(in_order[i]>='A' && in_order[i]<='Z')
            {
                print+=in_order[i];
                continue;
            }
            if(tmp.empty() || in_order[i]=='(')
            {
                tmp.push(in_order[i]);
                continue;
            }
            if(in_order[i]==')')
            {
                while(tmp.top()!='(')
                {
                    print+=tmp.top();
                    tmp.pop();
                }
                tmp.pop();
                continue;
            }
            if(op(tmp.top())<op(in_order[i]))tmp.push(in_order[i]);
            else
            {
                while(!tmp.empty() && op(tmp.top())>=op(in_order[i]))
                {
                    print+=tmp.top();
                    tmp.pop();
                }
                tmp.push(in_order[i]);
            }
        }
    }
    while(!tmp.empty())
    {
        print+=tmp.top();
        tmp.pop();
    }

    cout<<print;

}