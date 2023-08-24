#include<bits/stdc++.h>
using namespace std;

int N,K;//보석 개수, 가방 개수
pair<int,int>jewelry[300001];
int max_weight[300001];
priority_queue<int,vector<int>,less<int>> pq;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>K;

   for(int i=0;i<N;++i)
   {
       int tmp1,tmp2;cin>>tmp1>>tmp2;
       jewelry[i].first = tmp1;jewelry[i].second = tmp2;
   }
   for(int i=0;i<K;++i)
   {
       cin>>max_weight[i];
   }
   sort(jewelry,jewelry+N);
   sort(max_weight,max_weight+K);

   int idx = 0;
   long long sum = 0;
   for(int i=0;i<K;++i)
   {
       while(idx<N && max_weight[i]>=jewelry[idx].first)
       {
           pq.push(jewelry[idx].second);
           idx++;
       }
       if(!pq.empty())
       {
           sum+=pq.top();
           pq.pop();
       }
   }
   cout<<sum;

}