#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> String(3);
    for (int i=0;i<3;++i)
    {
        cin>>String[i];
    }

    for (int i=0;i<3;++i)
    {
        if (String[i]!="Fizz" && String[i]!="Buzz" && String[i]!="FizzBuzz")
        {
            int res = stoi(String[i])+3-i;//i=2면 +1,i=1ㅇ면 +2, i=0lㅇ면 3
            if (res%3 ==0 && res%5==0)
            {
                cout<<"FizzBuzz";
                return 0;
            }
            if (res%3 ==0)
            {
                cout<<"Fizz";
                return 0;
            }
            if (res % 5 ==0)
            {
                cout<<"Buzz";
                return 0;
            }
            cout<<res;
            return 0;
        }
    }
}