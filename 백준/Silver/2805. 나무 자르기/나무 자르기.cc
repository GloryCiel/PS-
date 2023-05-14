#include <iostream>


using namespace std;

int main(){
    int N, M;cin >> N >> M;
    long long* tree = new long long[N];
    for (int i = 0; i < N;i++)
    {
        cin >> tree[i];
    }

    long long high = 1000000000;
    long long low = 0;
    long long mid;
    long long cut_tree;
    long long ans = 0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        cut_tree = 0;
        for (int i = 0; i < N; i++)
        {
            if(tree[i] > mid)
            {
                cut_tree += (tree[i] - mid);
            }
        }
        if(cut_tree == M)
        {
            ans = mid;
            break;
        }
        else if(cut_tree > M)
        {
            if(ans < mid)
            {
                ans = mid;
            }
            low = mid + 1;
        }
        else if(cut_tree < M)
        {
            high = mid - 1;
        }
    }
    cout << ans;
}
