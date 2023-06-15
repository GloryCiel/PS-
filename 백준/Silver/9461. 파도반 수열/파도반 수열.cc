#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int T;cin>>T;
    vector<long long>sequence(101,0);
    sequence[1] = 1;
    sequence[2] = 1;
    sequence[3] = 1;

    for(int i=4;i<101;++i)
    {
        sequence[i] = sequence[i-2]+sequence[i-3];
    }

    for(int i=0;i<T;++i)
    {
        int tmp;cin>>tmp;
        cout<<sequence[tmp]<<'\n';
    }
}