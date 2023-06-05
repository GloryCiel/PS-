#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int n;cin>>n;
    if(n==0)
    {
        cout<<0<<endl;
    }

    else
    {
        int * difficulty = new int[n];

        for(int i=0;i<n;++i)
        {
            cin>>difficulty[i];
        }

        sort(difficulty,difficulty+n);
        int num = round(n*0.15);

        int sum=0;
        for(int i=num;i<n-num;++i)sum+=difficulty[i];
        double result = (double)sum/(double)(n-2*num);
        cout<<round(result)<<endl;
    }
}