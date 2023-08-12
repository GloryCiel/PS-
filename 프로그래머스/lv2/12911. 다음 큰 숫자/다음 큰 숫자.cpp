#include <string>
#include <vector>

using namespace std;

int many(int a)
{
    int cnt = 0;
    for(int i=0;a>0;++i)
    {
        if(a%2==1)cnt++;
        a/=2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int comp = many(n);
    for(;;)
    {
        n++;
        if(many(n)==comp)break;
    }
    return n;
}