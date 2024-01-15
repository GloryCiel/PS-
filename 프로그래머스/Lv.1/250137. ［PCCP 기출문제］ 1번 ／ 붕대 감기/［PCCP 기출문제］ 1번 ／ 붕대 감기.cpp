#include <string>
#include <vector>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
    int life = health;int cur = 0;
    for(int i=0;i<attacks.size();++i)
    {
        int time = attacks[i][0];int damage = attacks[i][1];
        int heal_time = time-cur;
        cur = time+1;
        int Q,remain;Q=heal_time/bandage[0];remain = heal_time%bandage[0];
        int heal = remain*bandage[1]+Q*bandage[1]*bandage[0]+Q*bandage[2];
        if(heal+life<=health)life= heal+life;
        else life = health;
        if(life-damage<=0)return -1;
        else life =life-damage;
    }
    return life;
}