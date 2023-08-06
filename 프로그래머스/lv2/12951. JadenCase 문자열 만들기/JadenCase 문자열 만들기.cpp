#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> TMP;
    string tmp;
    
    for(int i=0;i<s.size();++i)
    {
        if(s[i]!=' ')
        {
            tmp+=s[i];
        }
        
        else
        {
            TMP.push_back(tmp);
            tmp ="";
        }
    }
    TMP.push_back(tmp);
    
    for(int i=0;i<TMP.size();++i)
    {
        for(int j=0;j<TMP[i].size();++j)
        {
            if(j==0)
            {
                if(TMP[i][j]>='a' && TMP[i][j]<='z')
                    TMP[i][j]-=32;
            }
            else
            {
                if(TMP[i][j]>='A' && TMP[i][j]<='Z')
                    TMP[i][j]+=32;
            }
        }
    }
    for(int i=0;i<TMP.size()-1;++i)
        answer=answer+TMP[i]+" ";
    answer+=TMP[TMP.size()-1];
    
    return answer;
}