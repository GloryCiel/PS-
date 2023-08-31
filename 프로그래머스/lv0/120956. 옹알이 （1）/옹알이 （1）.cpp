#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling)
{
    int answer=0;
    vector<string> possible_2={"ye","ma"};
    vector<string> possible_3={"aya","woo"};

    for(int i=0;i<babbling.size();++i)
    {
        int length = babbling[i].size();
        int now = 0;
        bool ans = true;
        while(now<length)
        {
            bool chk = false;
            string sub1,sub2;
            if(now+2<=length) sub1 = babbling[i].substr(now,2);
            if(now+3<=length) sub2 = babbling[i].substr(now,3);

            for(int j=0;j<2;++j)
            {
                if(sub1 == possible_2[j])
                {
                    now+=2;
                    chk = true;
                }
            }

            if(!chk)
            {
                for(int j=0;j<2;++j)
                {
                    if(sub2 == possible_3[j])
                    {
                        now+=3;
                        chk = true;
                    }
                }
            }
            if(!chk)
            {
                ans= false;
                break;
            }
        }
        if(ans)answer++;
    }
    return answer;
}