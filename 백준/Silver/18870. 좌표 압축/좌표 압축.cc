#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int N;cin>>N;
    vector<long long>axis;
    for(int i=0;i<N;++i)
    {
        long long tmp;cin>>tmp;
        axis.push_back(tmp);
    }
    vector<long long>sorted_axis = axis;
    sort(sorted_axis.begin(),sorted_axis.end());
    long long last = unique(sorted_axis.begin(),sorted_axis.end())-sorted_axis.begin();
    vector<long long>tmp;
    for(int i=0;i<last;++i)
        tmp.push_back(sorted_axis[i]);

    for(int i=0;i<N;++i)
    {
        int res = lower_bound(tmp.begin(),tmp.end(),axis[i])- tmp.begin();
        cout<<res<<' ';
    }
}