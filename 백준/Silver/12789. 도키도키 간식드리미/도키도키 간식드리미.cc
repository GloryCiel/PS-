#include<bits/stdc++.h>
using namespace std;

int arr[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num = 1, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (s.empty() && cnt < n) {
            s.push(arr[cnt++]);
        }
        while (s.top() != num && cnt < n) {
            s.push(arr[cnt++]);
        }
        if (!s.empty() && s.top() == num) {
            s.pop();
            num++;
        } else {
            printf("Sad\n");
            return 0;
        }
    }
    printf("Nice\n");

    return 0;
}