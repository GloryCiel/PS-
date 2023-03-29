#include <iostream>
using namespace std;

int main()
{
    for(;;)
    {
        int a,b;cin>>a>>b;
        if(a==0 && b==0)
            break;
        if(a<b)
        {
            if(!(b%a))
                cout<<"factor"<<endl;
            else
                cout<<"neither"<<endl;
        }
        else
        {
            if(!(a%b))
                cout<<"multiple"<<endl;
            else
                cout<<"neither"<<endl;
        }
    }
}