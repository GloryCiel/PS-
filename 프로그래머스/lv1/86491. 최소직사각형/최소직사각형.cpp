#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    for(int i=0;i<sizes.size();++i)
    {
        if(sizes[i][1]>sizes[i][0])
        {
            int tmp = sizes[i][1];
            sizes[i][1]=sizes[i][0];
            sizes[i][0]=tmp;
        }
    }
    int max1 = sizes[0][0],max2=sizes[0][1];
    for(int i=1;i<sizes.size();++i)
    {
        if(max1<sizes[i][0])max1=sizes[i][0];
        if(max2<sizes[i][1])max2=sizes[i][1];
    }
    return max1*max2;
}