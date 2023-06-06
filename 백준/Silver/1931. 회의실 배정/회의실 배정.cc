#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct conference
{
    int start;
    int end;
}conference;

bool compare(conference a,conference b)
{
    if(a.end==b.end)
        return a.start<b.start;
    return a.end<b.end;
}

int main()
{
    int N;cin>>N;
    vector<conference> conf(N);
    for(int i=0;i<N;++i)
    {
        cin>>conf[i].start>>conf[i].end;
    }

    sort(conf.begin(),conf.end(),compare);

    int result = 0;
    int cur = 0;
    for(int i=0;i<N;++i)
    {
        if(conf[i].start<cur) continue;

        ++result;
        cur = conf[i].end;
    }
    cout<<result<<endl;
}