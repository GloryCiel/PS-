#include <bits/stdc++.h>
using namespace std;

bool end_cheese(const string& S)
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
        if(end_cheese(names[i])) name_of_cheese.insert(names[i]);
        if(name_of_cheese.size()==4)
        {
            cout<<"yummy";
            return 0;
        }
    }
    cout<<"sad";
    return 0;
}