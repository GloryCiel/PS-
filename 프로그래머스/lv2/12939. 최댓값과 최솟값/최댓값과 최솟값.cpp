#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    vector<int>numbers;
    string answer;
    
    int idx = 0;
    string tmp;
    while(idx<s.size())
    {
        if(s[idx]!=' ')
        {
            tmp+=s[idx++];
        }
        else
        {
            numbers.push_back(stoi(tmp));
            idx++;
            tmp="";
        }
    }
    numbers.push_back(stoi(tmp));
    sort(numbers.begin(),numbers.end());
    answer=to_string(numbers[0])+" "+to_string(numbers[numbers.size()-1]);
    
    return answer;
}