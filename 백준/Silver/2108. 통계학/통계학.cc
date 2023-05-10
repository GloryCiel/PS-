#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int N;cin>>N;
    int * num = new int[N];
    int most[8001]={0,};
    double sum = 0;
    for(int i=0;i<N;++i)
    {
        cin>>num[i];
        sum+=num[i];
        most[num[i]+4000]++;
    }
    sort(num,num+N);
    int mean,median,mode,range;
    mean = round(sum/N);
    median = num[(N/2)];
    range = num[N-1]-num[0];
    int frequent = -1;

    bool is_second= false;

    for(int i=0;i<8001;++i)
    {
        if(most[i]==0)
            continue;
        if(most[i]==frequent)
        {
            if(is_second)
            {
                mode = i-4000;
                is_second = false;
            }
        }
        if(most[i]>frequent)
        {
            frequent = most[i];
            mode = i-4000;
            is_second = true;
        }
    }
    cout<<mean<<endl<<median<<endl<<mode<<endl<<range<<endl;
}