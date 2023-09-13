#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int a =x;
    int i = 0;
    while(i<n)
    {
        answer.push_back(a);
        a+=x;
        i++;
    }
    return answer;
}