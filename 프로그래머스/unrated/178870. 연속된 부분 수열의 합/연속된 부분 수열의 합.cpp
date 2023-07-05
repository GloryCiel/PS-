#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int>answer(2,0);
    int s=0,e=0;
    int len = sequence.size()+1;
    int p_sum=sequence[0];
    while(s<=e && e <sequence.size())
    {
        if(p_sum<k)p_sum+=sequence[++e];
        else if(p_sum == k)
        {
            if(e-s+1<len)
            {
                len = e-s+1;
                answer[0]=s,answer[1]=e;
            }
            else if(e-s+1 == len)
            {
                if(s<answer[0])
                {
                    answer[0]=s;
                    answer[1]=3;
                }
            }
            p_sum-=sequence[s++];
        }
        else p_sum-=sequence[s++];
    }
    return answer;
}