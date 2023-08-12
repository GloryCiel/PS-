#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int left=1,right=1;
    vector<int> nums(n+1,0);
    for(int i=0;i<=n;++i) nums[i]=i;
    while(left<=n)
    {
        int sub_sum=0;
        for(int i=left;i<right;++i)
            sub_sum+=nums[i];
        if(sub_sum<n)
            right++;
        else
        {
            if(sub_sum==n)
            {
                answer++;
                left++;
            }
            else
                left++;
        }
    }
    
    
    return answer;
}