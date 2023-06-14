#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
    if(a.second == b.second)
        return a.first<b.first;
    return a.second<b.second;
}


int solution(vector<vector<int>> targets) {
    int answer = 0;
    vector<pair<int,int>> Target;
    vector<bool>selected(targets.size(),false);
    for(int i=0;i<targets.size();++i)
    {
        Target.push_back(make_pair(targets[i][0],targets[i][1]));
    }
    
    sort(Target.begin(),Target.end(),compare);
    
    for(int i=0;i<Target.size();++i)
    {
        for(int j=i+1;j<Target.size();++j)
        {
            if(selected[i])
                break;
            if(Target[i].second>Target[j].first && !selected[j])
            {
                selected[j]=true;
            }
        }
        if(!selected[i])
        {
            answer++;
            selected[i]==true;
        }
    }
    
    
    return answer;
}