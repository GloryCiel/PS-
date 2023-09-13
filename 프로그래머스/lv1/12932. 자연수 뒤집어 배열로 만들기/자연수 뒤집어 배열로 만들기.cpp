#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string test = to_string(n);
    for(int i=test.size()-1;i>=0;--i)
    {
        answer.push_back(test[i]-'0');
    }
    return answer;
}