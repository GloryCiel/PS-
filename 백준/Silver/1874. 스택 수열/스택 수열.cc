#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> s;
    vector<char> result;

    int current = 1;
    for (int i = 0; i < n; i++) 
    {
        int num;
        cin >> num;

        while (current <= num) 
        {
            s.push(current);
            result.push_back('+');
            current++;
        }
        if (s.top() == num) 
        {
            s.pop();
            result.push_back('-');
        } 
        else 
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (char op : result)
    {
        cout << op << '\n';
    }

    return 0;
}