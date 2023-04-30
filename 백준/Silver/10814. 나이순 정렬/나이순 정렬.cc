#include<iostream>
#include<algorithm>
using namespace std;

typedef struct member
{
    int age,idx;
    string name;
}member;

bool compare(const member& p1,const member& p2)
{
    if(p1.age!=p2.age)
        return p1.age<p2.age;
    return p1.idx<p2.idx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;cin>>N;
    member * members = new member[N];

    for(int i=0;i<N;++i)
    {
        cin>>members[i].age>>members[i].name;
        members[i].idx = i;
    }
    sort(members,members+N,compare);
    for(int i=0;i<N;++i)
    {
        cout<<members[i].age<<" "<<members[i].name<<"\n";
    }
    delete[](members);
}