#include<bits/stdc++.h>
using namespace std;

void print(vector<int>numbers,vector<int>save,int M,int depth)
{
    if(depth==M)
    {
        for(int i=0;i<save.size();++i)
        {
            cout<<save[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<numbers.size();++i)
    {
        if(depth==0)
        {
            save[depth]=numbers[i];
            print(numbers,save,M,depth+1);
        }
        else
        {
            if(save[depth-1]<=numbers[i])
            {
                save[depth]=numbers[i];
                print(numbers,save,M,depth+1);
            }
            else continue;
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
    vector<int>save(M,0);
    for(int i=0;i<N;++i)
    {
        int tmp;cin>>tmp;
        numbers.push_back(tmp);
    }
    sort(numbers.begin(),numbers.end());
    print(numbers,save,M,0);

}