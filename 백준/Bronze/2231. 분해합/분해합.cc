#include<iostream>
#include<string>
using namespace std;

int pow(int,int);
int divsum(int,int);

int main()
{
    string Number;cin>>Number;
    int N = stoi(Number);
    int real_result = 0;
    for(int i=1;i<=N;++i)
    {
        string tmp = to_string(i);
        int result = divsum(i,tmp.length());
        if(result==N)
        {
            real_result = i;
            break;
        }
    }
    cout<<real_result<<endl;
}

int divsum(int number,int digit)
{
    int * arr = new int[digit];
    for(int i=0;i<digit;++i)
    {
        arr[i]= number /pow(10, digit - i - 1);
        number=number-arr[i]*(int)pow(10,digit-i-1);
    }
    int result = 0;
    for(int i=0;i<digit;++i)
    {
        result=result+arr[i]+arr[i]*(int)pow(10,digit-i-1);
    }
    return result;
}

int pow(int a,int b)
{
    int result = 1;
    for(int i=0;i<b;++i)
    {
        result*=a;
    }
    return result;
}