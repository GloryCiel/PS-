#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int first = arr[0];
    answer.push_back(first);
    for(int i=1;i<arr.size();++i)
    {
        if(first==arr[i])
            continue;
        else
        {
            first = arr[i];
            answer.push_back(first);
        }
    }
    

    return answer;
}