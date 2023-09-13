#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string tmp = to_string(n);
    vector<int>ans;
    for(int i=0;i<tmp.size();++i)ans.push_back(tmp[i]-'0');
    sort(ans.begin(),ans.end());
    long long j = 1;
    for(int i=0;i<ans.size();++i)
    {
        answer = answer+j*ans[i];
        j*=10;
    }
    return answer;
}