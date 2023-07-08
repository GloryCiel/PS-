#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int up,left,right,down;
    bool flag =false;
    
    for(int i=0;i<wallpaper.size();++i)
    {
        for(int j=0;j<wallpaper[0].size();++j)
        {
            if(wallpaper[i][j]=='#')
            {
                up = i;
                flag =true;
                break;
            }
        }
        if(flag)
            break;
    }
    flag = false;
    
    for(int i=wallpaper.size()-1;i>=0;--i)
    {
        for(int j=0;j<wallpaper[0].size();++j)
        {
            if(wallpaper[i][j]=='#')
            {
                down = i;
                flag  = true;
                break;
            }
        }
        if(flag)
            break;
    }
    
    flag = false;
    
    for(int i=0;i<wallpaper[0].size();++i)
    {
        for(int j=0;j<wallpaper.size();++j)
        {
            if(wallpaper[j][i]=='#')
            {
                left = i;
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    
    flag = false;
    
    for(int i=wallpaper[0].size()-1;i>=0;--i)
    {
        for(int j=0;j<wallpaper.size();++j)
        {
            if(wallpaper[j][i]=='#')
            {
                right =i;
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    
    right+=1;
    down+=1;
    
    answer.push_back(up);
    answer.push_back(left);
    answer.push_back(down);
    answer.push_back(right);
    
    
    return answer;
}