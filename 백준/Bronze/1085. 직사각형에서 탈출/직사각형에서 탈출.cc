#include <iostream>
using namespace std;

int main()
{
    int x,y,w,h;cin>>x>>y>>w>>h;

    int min1, min2;
    min1 = (x<w-x)?x:w-x;
    min2 = (y<h-y)?y:h-y;
    int result = (min1<min2)?min1:min2;

    cout<<result<<endl;
}