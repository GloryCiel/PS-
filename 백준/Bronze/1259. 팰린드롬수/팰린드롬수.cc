#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    for(;;)
    {
        int number;cin>>number;
        if(!number)
            break;
        if(number<10)
            cout<<"yes"<<endl;
        else
        {
            int length=0,tmp=number;
            while(tmp!=0)
            {
                tmp=tmp/10;
                ++length;
            }
            vector<int>a(length);
            tmp = number;
            for(int i=0;i<length;i++)
            {
                a[i]=tmp/(pow(10,length-i-1));
                tmp=tmp%(int)pow(10,length-i-1);
            }
            int par=1;
            for(int i=0;i<length/2;i++)
            {
                if(a[i]!=a[length-i-1])
                {
                    cout<<"no"<<endl;
                    par=0;
                    break;
                }
            }
            if(par)
                cout<<"yes"<<endl;
        }
    }
}