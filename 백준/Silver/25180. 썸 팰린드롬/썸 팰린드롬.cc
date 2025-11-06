#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    if (!(cin >> N)) return 0;

    // 1) 한 자리로 가능한 경우
    if (N <= 9) {
        cout << 1 << '\n';
        return 0;
    }

    const long long B = 18;

    // 3) 홀수 길이 후보: k_odd = max(1, ceil((N-9)/18))
    auto ceil_div = [](long long a, long long b) {
        return (a + b - 1) / b;
    };

    long long k_odd = max(1LL, ceil_div(N - 9, B));
    long long L_odd = 2 * k_odd + 1;

    // 2) 짝수 길이 후보 (N이 짝수일 때만)
    long long ans = L_odd; // 우선 홀수 후보로 초기화
    if (N % 2 == 0) {
        long long k_even = ceil_div(N, B); // 18k >= N
        long long L_even = 2 * k_even;
        ans = min(ans, L_even);
    }

    cout << ans << '\n';
    return 0;
}