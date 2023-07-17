#include <string>
#include <vector>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    int my=r1,MY=r2;
    
    for(int i=0;i<r2;++i)
    {
        while(r2*r2<MY*MY+i*i)
        {
            MY--;
        }
        while(my-1 &&(r1*r1<=(my-1)*(my-1)+i*i))
            my--;
        answer+=(MY-my)+1;
    }
    
    return 4*answer;
    
}