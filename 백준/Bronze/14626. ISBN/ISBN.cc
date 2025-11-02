#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string isbn;
    cin >> isbn;

    vector<int> num_isbn(13, -1);
    int pos = -1;

    for (int i = 0; i < 13; ++i) {
        if (isbn[i] == '*') {
            pos = i;
        } else {
            num_isbn[i] = isbn[i] - '0';
        }
    }

    int wsum = 0;
    for (int i = 0; i < 12; ++i) {
        if (i == pos) continue;
        if (i % 2 == 0) wsum += num_isbn[i];
        else            wsum += 3 * num_isbn[i];
    }

    int check = num_isbn[12];
    int need = (10 - ((wsum + check) % 10)) % 10;
    int w = (pos % 2 == 0) ? 1 : 3;

    int x;
    if (w == 1) x = need;
    else        x = (7 * need) % 10;

    cout << x;
    return 0;
}