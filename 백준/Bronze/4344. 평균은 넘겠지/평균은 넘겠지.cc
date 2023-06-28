#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int C;cin>>C;
    while(C--)
    {
        int N;cin>>N;
        vector<int>score(N,0);
        double mean = 0;
        for(int i=0;i<N;++i)
        {
            int tmp;cin>>tmp;
            mean+=tmp;
            score[i]=tmp;
        }
        mean = mean/N;
        int cnt=0;
        for(int i = 0;i<N;++i)
        {
            if(score[i]>mean)
                cnt++;
        }
        double result = (double)cnt*100/N;

        cout<<fixed;
        cout.precision(3);
        cout<<result<<"%\n";
    }
}