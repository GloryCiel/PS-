#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack <int>number;
    int K;cin>>K;
    for(int i=0;i<K;++i)
    {
        int tmp;cin>>tmp;
        if(tmp!=0)
            number.push(tmp);
        else
            number.pop();
    }
    int result = 0;
    while(!number.empty())
    {
        result +=number.top();
        number.pop();
    }
    cout<<result;
}