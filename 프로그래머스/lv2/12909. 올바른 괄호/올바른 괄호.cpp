#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char>bracket;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='(') bracket.push('(');
        
        else
        {
            if(!bracket.empty())
                bracket.pop();
            else
            {
                return false;
            }
        }
    }
    if(bracket.empty()) return true;
    else return false;
    
    
}