#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    bool flag = false;
    for(long long i=1;i<=sqrt(n);++i)
    {
        if(i*i==n)
        {
            flag = true;
            answer = i+1;
        }
    }
    if(flag)return answer*answer;
    else return -1;
}