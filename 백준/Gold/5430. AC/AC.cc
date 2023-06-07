#include<iostream>
#include<deque>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int T;cin>>T;
    for(int i=0;i<T;++i)
    {
        string p;cin>>p;
        int n;cin>>n;
        deque <int> array;
        int cnt = 0;
        string expression;cin>>expression;
        string tmp;
        for(int j=1;j<expression.size();++j)
        {
            if(cnt==n) break;
            if(expression[j+1]>='0' &&expression[j+1]<='9')
            {
                if(expression[j]>='0' &&expression[j]<='9')
                    tmp+=expression[j];
            }
            else
            {
                tmp+=expression[j];
                cnt++;
                array.push_back(stoi(tmp));
                tmp = "";
            }
        }//입력 끝
        int R_cnt=0;
        bool error = false;

        for(int j=0;j<p.size();++j)
        {
            if(p[j]=='R')
                R_cnt++;
            else
            {
                if(!array.empty())
                {
                    if(R_cnt%2==0)
                    {
                        array.pop_front();
                    }
                    else
                        array.pop_back();
                }
                else
                {
                    cout<<"error\n";
                    error=true;
                    break;
                }
            }
        }
        if(!error && array.size()!=0)
        {
            if(R_cnt%2==0)
            {
                cout<<'[';
                for(int j=0;j<array.size()-1;++j)
                    cout<<array[j]<<',';
                cout<<array[array.size()-1]<<"]\n";
            }
            else
            {
                cout<<'[';
                for(int j=array.size()-1;j>=1;--j)
                    cout<<array[j]<<',';
                cout<<array[0]<<"]\n";
            }
        }
        if(!error && array.size()==0)
        {
            cout<<"[]\n";
        }
    }
}