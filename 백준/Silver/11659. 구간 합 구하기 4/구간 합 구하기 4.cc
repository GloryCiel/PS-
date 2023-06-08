#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;cin>>N>>M;
    vector<int> number;
    int sub_sum=0;
    for(int i=0;i<N;++i)
    {
        int tmp;cin>>tmp;
        sub_sum+=tmp;
        number.push_back(sub_sum);
    }
    for(int i=0;i<M;++i)
    {
        int a,b;cin>>a>>b;
        if(a==1)
        {
            cout<<number[b-1]<<'\n';
        }
        else
        {
            cout<<number[b-1]-number[a-2]<<'\n';
        }
    }
}