#include<iostream>
#include<algorithm>

using namespace std;

typedef struct person
{
    int weight;
    int height;
}person;

int main()
{
    int N;cin>>N;
    person *people = new person[N];

    for(int i=0;i<N;++i)
    {
        cin>>people[i].weight>>people[i].height;
    }

    for(int i=0;i<N;++i)
    {
        int bigger=0;
        for(int j=0;j<N;++j)
        {
            if(j==i) continue;
            if(people[i].weight<people[j].weight && people[i].height<people[j].height) bigger++;
        }
        cout<<bigger+1<<' ';
    }
}