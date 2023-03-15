#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int K,N;cin>>K>>N;
    vector<long long> have;
    long long high = -1;
    for(int i=0;i<K;++i)
    {
        long long tmp;cin>>tmp;
        if(high<tmp)
            high = tmp;
        have.push_back(tmp);
    }
    long long low=1, mid;
    long long result = 0;

    while(low<=high)
    {
        mid = (low+high)/2;
        long long number = 0;
        for(int i=0;i<K;++i)
        {
            number+=have[i]/mid;
        }
        if(number>=N)
        {
            low = mid+1;
            if(result<mid) result = mid;
        }
        else
        {
            high = mid -1;
        }
    }
    cout<<result;
}