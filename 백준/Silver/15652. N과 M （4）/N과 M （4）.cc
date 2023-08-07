#include<bits/stdc++.h>
using namespace std;

void duplicated_permutation(vector<int> numbers, vector<int> r,int depth)
{
    if(depth == r.size())
    {
        for(int i=0;i<r.size();++i)
        {
            cout<<r[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<numbers.size();++i)
    {
        if(depth==0)
        {
            r[depth]=numbers[i];
            duplicated_permutation(numbers,r,depth+1);
        }
        else
        {
            if(r[depth-1]<=numbers[i])
            {
                r[depth]=numbers[i];
                duplicated_permutation(numbers,r,depth+1);
            }
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;cin>>N>>M;
    vector<int>numbers;
    for(int i=0;i<N;++i) numbers.push_back(i+1);
    vector<int>r(M,0);
    duplicated_permutation(numbers,r,0);

}