#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack <char> test;
    test.push(s[0]);
    for(int i=1;i<s.size();++i)
    {
        if(test.empty())
        {
            test.push(s[i]);
        }
        else
        {
            if(test.top()!=s[i]) test.push(s[i]);
            else test.pop();
        }
    }
    if(test.empty())
        return 1;
    return 0;
}