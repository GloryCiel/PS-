#include <bits/stdc++.h>
using namespace std;

bool end_cheese(string S)
{
    string suffix = "Cheese";
    if(S.size()<suffix.size()) return false;
    else
    {
        return S.compare(S.size()-suffix.size(),suffix.size(),suffix)==0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;cin>>N;
    vector<string> names(N);
    for(int i=0;i<N;++i) cin>>names[i];
    if(N<4)
    {
        cout<<"sad";
        return 0;
    }
    set<string> name_of_cheese;

    for(int i=0;i<N;++i)
    {
        bool is_cheese = end_cheese(names[i]);
        if(is_cheese) name_of_cheese.insert(names[i]);
        if(name_of_cheese.size()==4)
        {
            cout<<"yummy";
            return 0;
        }
    }
            if(name_of_cheese.size()==4)
        {
            cout<<"yummy";
            return 0;
        }
        else{
            cout<<"sad";
            return 0;
        }
}