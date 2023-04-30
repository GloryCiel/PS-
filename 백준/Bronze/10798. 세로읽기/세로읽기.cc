#include <iostream>
using namespace std;

int main()
{
    char arr[5][15];
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<15;++j)
        {
            arr[i][j]='-';
        }
    }

    for(int i=0;i<5;++i)
    {
            cin>>arr[i];
    }
    
    
    for(int j=0;j<15;++j)
    {
        for(int i=0;i<5;i++)
        {
            if(arr[i][j]!='-' && arr[i][j]!='\000')
            {
                cout << arr[i][j];
            }
        }
    }
}
