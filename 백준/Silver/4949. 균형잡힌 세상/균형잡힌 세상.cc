#include<iostream>
#include<string>
#include<stack>

using namespace std;
string str;

int main()
{
    for(;;)
    {
        getline(cin, str);
        stack<char> bracket;
        if (str[0] == '.') break;

        for (int i = 0; i < str.length() - 1; i++)
        {
            if (str[i] == '(') bracket.push('(');
            if (str[i] == '[') bracket.push('[');
            if (str[i] == ']')
            {
                if (!bracket.empty() && bracket.top() == '[') bracket.pop();
                else { printf("no\n"); break; }
            }

            if (str[i] == ')')
            {
                if (!bracket.empty() && bracket.top() == '(') bracket.pop();
                else { printf("no\n"); break; }
            }

            if (bracket.empty() && i == str.length() - 2) printf("yes\n");
            else if (!bracket.empty() && i == str.length() - 2) printf("no\n");
        }

    }
}