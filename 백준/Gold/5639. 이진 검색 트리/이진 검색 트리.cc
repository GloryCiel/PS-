#include<bits/stdc++.h>
using namespace std;

void pre_to_post(vector<int> &preorder,int start, int end, vector<int>& postorder)
{
    if(start>end) return;

    int root = preorder[start];
    int right_subtree_start = end+1;

    for(int i=start+1;i<=end;++i)
    {
        if(preorder[i]>root)
        {
            right_subtree_start=i;
            break;
        }
    }

    pre_to_post(preorder,start+1,right_subtree_start-1,postorder);
    pre_to_post(preorder,right_subtree_start,end,postorder);

    postorder.push_back(root);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tmp;
    vector<int> preorder;
    vector<int> postorder;
    while(cin>>tmp)
    {
        preorder.push_back(tmp);
    }

    pre_to_post(preorder,0,preorder.size()-1,postorder);

    for(int i:postorder)cout<<i<<'\n';


}