#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    vector<int> cnt(n,0);

    map<string,int>word;
    cnt[0]++;
    int now = 1;
    word.insert(make_pair(words[0],1));
    for(int i=1;i<words.size();++i)
    {
        if(now>=n)now=0;
        cnt[now]++;
        if(words[i-1].back()!=words[i].front())
        {
            answer.push_back(now+1);
            answer.push_back(cnt[now]);
            return answer;
        }
        if(word.find(words[i])==word.end())
        {
            word.insert(make_pair(words[i],1));
            now++;
        }
        else
        {
            answer.push_back(now+1);
            answer.push_back(cnt[now]);
            return answer;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;

}
