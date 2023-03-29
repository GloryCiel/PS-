#include <iostream>
using namespace std;

int main()
{
    for(;;)
    {
        int nums[100000] = {0};
        int a = 0;
        int n;cin>>n;
        int result = 0;
        if(n==-1)
            break;
        for(int i=1;i<n;++i)
        {
            if(!(n%i))
            {
                nums[a++]=i;
                result+=i;
            }
        }
        if(result == n)
        {
            cout<< result<< " = ";
            int i=0;
            while(nums[i])
            {
                if(nums[i+1]!=0)
                    cout<<nums[i++]<<" + ";
                else
                {
                    cout<<nums[i]<<endl;
                    break;
                }
            }
        }
        else
        {
            cout<<n<<" is NOT perfect."<<endl;
        }
    }

}