#include<iostream>
#include<cmath>

using namespace std;

long solution(string sentence,int length)
{
    int r = 31;int M =1234567891;

    int *arr = new int[length];
    for(int i=0;i<length;++i)
    {
        arr[i]=sentence[i]-96;
    }

    long long result=0;
    long long R = 1;
    for(int i =0;i<length;++i)
    {
        result = (result + (arr[i])*R)%M;
        R = (R*r)%M;
    }
    return result;

}

int main()
{
    int L;cin>>L;
    string to_hash;cin>>to_hash;
    cout<<solution(to_hash,L)<<endl;
}

