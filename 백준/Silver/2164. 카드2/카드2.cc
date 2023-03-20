#include <iostream>
#include<list>
using namespace std;

int main()
{
    int N;cin>>N;
    list<int>cards;
    for(int i=0;i<N;++i)
    {
        cards.push_back(i+1);
    }
    while(cards.size()!=1)
    {
        cards.pop_front();
        int tmp = cards.front();
        cards.pop_front();
        cards.push_back(tmp);
    }
    cout<<cards.front();
}