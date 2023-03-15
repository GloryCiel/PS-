#include <iostream>
#include <cmath>
using namespace std;

int calc(int,int);

int main()
{
    int N;cin>>N;
    for(int i=0;i<N;++i)
    {
        int start,end;cin>>start>>end;
        cout<<calc(start,end)<<'\n';
    }
}

int calc (int a, int b)
{
    int c;
    int distance = b-a;
    int result = 0;
    c = sqrt(distance);
    if(pow(c,2)==distance)
    {
        result = 2*c-1;
    }
    else
    {
        result = 2*c;
    }
    if(distance>c*(c+1))
        result+=1;

    return result;
}