#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());

    int left=0,right=people.size()-1;
    while(left<=right)
    {
        answer+=1;
        if(people[left]+people[right]<=limit)
        {
            left++;
        }
        right--;
    }

    return answer;
}