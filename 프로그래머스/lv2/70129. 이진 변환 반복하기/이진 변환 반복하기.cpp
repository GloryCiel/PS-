#include <string>
#include <vector>

using namespace std;

string S;

void f(int num)
{
    if(num>1)f(num/2);
    S+=to_string(num%2);
}

vector<int> solution(string s) {
    vector<int> answer(2,0);
    while(s!="1")
    {
        int cnt = 0;
        for(int i=0;i<s.size();++i)
            if(s[i]=='0')cnt++;
        answer[1]+=cnt;
        int tmp = s.size()-cnt;
        f(tmp);
        s=S;
        S="";
        answer[0]++;
    }
    return answer;
}