#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>PAIR;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   int N;cin>>N;
   vector<PAIR>arr(N);

   for(int i=0;i<N;++i)cin>>arr[i].first>>arr[i].second;
   sort(arr.begin(),arr.end());

   priority_queue<int,vector<int>,greater<int>>pq;
   for(int i=0;i<N;++i)
   {
       if(pq.size()<arr[i].first)pq.push(arr[i].second);
       else
       {
           if(pq.top()<arr[i].second)
           {
               pq.pop();
               pq.push(arr[i].second);
           }
       }
   }
   int res = 0;
   while(!pq.empty())
   {
       res+=pq.top();
       pq.pop();
   }
   cout<<res;
   
}