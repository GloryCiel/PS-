#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
    if(a.second == b.second)
    {
        return a.first<b.first;
    }
    return a.second<b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;cin>>N;
    vector<pair<int,int>> human_time(N);

    for(int i=0;i<N;++i)
    {
        cin>>human_time[i].second;
        human_time[i].first = i;
    }

    sort(human_time.begin(),human_time.end(),compare);

    int result = 0;
    for(int i=0;i<N;++i)
    {
        result+=(N-i)*(human_time[i].second);
    }
    cout<<result<<endl;
}