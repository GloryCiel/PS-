#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> factor;
    for(int i=1;i<=brown+yellow;++i)
    {
        if((brown+yellow)%i==0) factor.push_back(i);
    }
    
    for(int i=0;i<factor.size();++i)
    {
        int width = factor[factor.size()-1-i],height=factor[i];
        if((width-2)*(height-2)==yellow)
        {
            answer.push_back(width);
            answer.push_back(height);
            return answer;
        }
    }
}