#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<int,string>rank_name;
    map<string,int>name_rank;
    for(int i=0;i<players.size();++i)
    {
        rank_name.insert(make_pair(i,players[i]));
        name_rank.insert(make_pair(players[i],i));
    }
    for(int i=0;i<callings.size();++i)
    {
        int called_now_rank = name_rank[callings[i]];
        string to_change_now_name = rank_name[called_now_rank-1];
        int tmp1=called_now_rank,tmp2=called_now_rank-1;
        string tmp3 = callings[i];string tmp4 =to_change_now_name;
        name_rank[tmp4]=tmp1;
        name_rank[tmp3]=tmp2;
        rank_name[tmp1]=tmp4;
        rank_name[tmp2]=tmp3;
    }
    for(int i=0;i<rank_name.size();++i)
    {
        answer.push_back(rank_name[i]);
    }
    return answer;
}