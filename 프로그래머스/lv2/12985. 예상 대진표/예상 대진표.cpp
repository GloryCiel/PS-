#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    if(a>b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int cnt = 0;
    while(b-a>=1)
    {
        if(a%2!=0)a++;
        if(b%2!=0)b++;
        a/=2;
        b/=2;
        cnt++;
    }
    return cnt;
}