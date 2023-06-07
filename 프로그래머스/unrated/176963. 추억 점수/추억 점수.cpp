#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    map <string,int> name_score;
    
    for(int i=0;i<name.size();++i)
    {
        name_score.insert(make_pair(name[i],yearning[i]));
    }
    
    for(int i=0;i<photo.size();++i)
    {
        int score=0;
        for(int j=0;j<photo[i].size();++j)
        {
            if(name_score.find(photo[i][j])!=name_score.end())
            {
                score+=name_score[photo[i][j]];
            }
        }
        answer.push_back(score);
    }
    
    return answer;
}