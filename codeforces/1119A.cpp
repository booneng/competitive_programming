#include <bits/stdc++.h>

using namespace std;

const int N = 300005;
long long a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    long long cnt = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (cnt && a[i] >= 2) {
            long long use = min(cnt, a[i] / 2);
            cnt -= use;
            a[i] -= use * 2;
            ans += use;
        }
        
        if (a[i] >= 3) {
            ans += a[i] / 3;
            a[i] = a[i] % 3;
        }

        cnt += a[i];
    }
    cout << ans;
}