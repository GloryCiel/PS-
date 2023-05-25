#include<iostream>
#include<algorithm>

using namespace std;

typedef struct axis
{
    int x;
    int y;
}axis;

bool compare(axis a, axis b)
{
    if(a.y==b.y)
    {
        return a.x<b.x;
    }
    return a.y<b.y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;cin>>N;
    axis* arr = new axis[N];
    for(int i=0;i<N;++i)
    {
        cin>>arr[i].x>>arr[i].y;
    }
    sort(arr,arr+N,compare);
    for(int i=0;i<N;++i)
        cout<<arr[i].x<<' '<<arr[i].y<<'\n';
}