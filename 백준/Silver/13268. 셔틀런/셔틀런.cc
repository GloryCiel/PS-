#include <bits/stdc++.h>

using namespace std;

int n, k;
void f(int a) {
    if (n <= 0) {
        printf("%d", a);
        exit(0);
    }
}

#define a(e) for(int i=1;i<=e;i++)n-=5,f(i)
#define b(e) for(int i=e;i>=1;i--)n-=5,f(i)

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;//100m 찍으면 초기화
    n%=100;

    for (int j = 0; j <= 4; j++) {
        a(j); ++n; b(j); --n; f(0);
    }

}