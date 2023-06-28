#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int s_i,s_j;
    
    for(int i=0;i<park.size();++i)
    {
        for(int j=0;j<park[0].size();++j)
        {
            if(park[i][j]=='S')
            {
                s_i=i;s_j=j;
            }
        }
    }
    
    for(int i=0;i<routes.size();++i)
    {
        string tmp = routes[i];
        char op = tmp[0];
        int num = tmp[2]-'0';
        
        if(op=='N')
        {
            int reset = s_i;
            for(int j=0;j<num;++j)
            {
                if(s_i-1>=0)
                {
                    if(park[s_i-1][s_j]!='X')
                    {
                        s_i=s_i-1;
                    }
                    else
                    {
                        s_i = reset;
                        break;
                    }
                }
                else
                {
                    s_i = reset;
                    break;
                }
            }
        }
        
        else if(op=='E')
        {
            int reset = s_j;
            for(int j=0;j<num;++j)
            {
                if(s_j+1<park[0].size())
                {
                    if(park[s_i][s_j+1]!='X')
                    {
                        s_j=s_j+1;
                    }
                    else
                    {
                        s_j = reset;
                        break;
                    }
                }
                else
                {
                    s_j = reset;
                    break;
                }
            }
        }
        
        else if(op=='W')
        {
            int reset = s_j;
            for(int j=0;j<num;++j)
            {
                if(s_j-1>=0)
                {
                    if(park[s_i][s_j-1]!='X')
                    {
                        s_j=s_j-1;
                    }
                    else
                    {
                        s_j = reset;
                        break;
                    }
                }
                else
                {
                    s_j = reset;
                    break;
                }
            }
        }
        
        else if(op == 'S')
        {
            int reset = s_i;
            for(int j=0;j<num;++j)
            {
                if(s_i+1<park.size())
                {
                    if(park[s_i+1][s_j]!='X')
                    {
                        s_i=s_i+1;
                    }
                    else
                    {
                        s_i = reset;
                        break;
                    }
                }
                else
                {
                    s_i = reset;
                    break;
                }
            }
        }
        
    }
    
    answer.push_back(s_i);answer.push_back(s_j);
    
    return answer;
}