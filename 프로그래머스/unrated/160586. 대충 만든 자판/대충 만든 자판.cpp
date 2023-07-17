#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> min_bun((int)('z'-'a')+1,-1);
    
    for(int i=0;i<keymap.size();++i)
    {
        for(int j=0;j<keymap[i].size();++j)
        {
            if(min_bun[keymap[i][j]-'A']==-1)
                min_bun[keymap[i][j]-'A']=j+1;
            else
            {
                min_bun[keymap[i][j]-'A']=min(j+1,min_bun[keymap[i][j]-'A']);
            }
        }
    }
    
    for(int i=0;i<targets.size();++i)
    {
        int result = 0;bool flag = false;
        for(int j=0;j<targets[i].size();++j)
        {
            if(min_bun[targets[i][j]-'A']!=-1)
            {
                result+=min_bun[targets[i][j]-'A'];
            }
            else
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            answer.push_back(result);
        }
        else
            answer.push_back(-1);
    }
    
    return answer;
}