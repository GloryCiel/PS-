#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int T;cin>>T;

    for(int i=0;i<T;++i)
    {
        stack<char> A;
        int flag = 0;
        string tmp;cin>>tmp;
        for(int i=0;i<tmp.length();++i)
        {
            flag = 0;
            if(tmp[i]=='(')
            {
                A.push(tmp[i]);
            }
            else
            {
                if(!A.empty())
                    A.pop();
                else
                 {
                    flag = 1;
                    break;
                 }
            }
        }
        if(A.empty()&&flag!=1)
        {
            cout<<"YES"<<endl;
        }
        else 
        {
            cout<<"NO"<<endl;
        }
    }
}