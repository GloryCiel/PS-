#include <string>
#include <vector>
#include <cmath>

using namespace std;

int GCD(int a,int b)
{
    if(b==0) return a;
    return GCD(b,a%b);
}

int solution(vector<int> arr) 
{
    int answer = 0;
    if(arr.size()==1)return arr[0];
    else if(arr.size()==2)return arr[0]*arr[1]/GCD(arr[0],arr[1]);
    else
    {
        int f_lcm = arr[0]*arr[1]/GCD(arr[0],arr[1]);
        for(int i=2;i<arr.size();++i)
        {
            f_lcm = f_lcm*arr[i]/GCD(f_lcm,arr[i]);
        }
        answer = f_lcm;
    }
    return answer;
}