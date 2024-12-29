#include <bits/stdc++.h>
using namespace std;

int max_fruit_tanghuru(int N, const vector<int>& S) {
    int left = 0, max_len = 0;
    unordered_map<int, int> fruit_count; // 과일 종류와 개수를 저장

    for (int right = 0; right < N; ++right) {
        // right 포인터에 해당하는 과일을 카운트
        fruit_count[S[right]]++;

        // 과일 종류가 3개 이상이면 left 포인터를 이동시킴
        while (fruit_count.size() > 2) {
            fruit_count[S[left]]--;
            if (fruit_count[S[left]] == 0) {
                fruit_count.erase(S[left]);
            }
            left++;
        }

        // 두 종류 이하의 과일만 있는 구간에서 최대 길이 계산
        max_len = max(max_len, right - left + 1);
    }

    return max_len;
}

int main() {
    int N;
    cin >> N;
    vector<int> S(N);

    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    // 결과 출력
    cout << max_fruit_tanghuru(N, S) << endl;

    return 0;
}