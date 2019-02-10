#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int l;
    cin >> l;
    deque<int> a(l);
    for (int i = 0; i < l; i++) {
        cin >> a[i];
    }

    while (a.size() && a.front() == 0) a.pop_front();
    while (a.size() && a.back() == 0) a.pop_back();
    if (a.size() == 0) {
        cout << 0;
        return 0;
    }

    int n = a.size();

    long long dp[200005][5];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            dp[i][j] = 1e18;
        }
    }

    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            long long val = dp[i][j];
            if (val >= (long long)1e18) continue;
            if (j == 0) {
                dp[i + 1][0] = min(dp[i + 1][0], val + a[i]);
            }
            else {
                dp[i + 1][4] = min(dp[i + 1][4], val + a[i]);
            }

            if (j <= 2) {
                dp[i + 1][2] = min(dp[i + 1][2], val + (a[i] % 2 == 0));
            }

            if (j <= 1) {
                dp[i + 1][1] = min(dp[i + 1][1], val + (a[i] == 0 ? 2 : (a[i] & 1)));
            }
            else if (j <= 3) {
                dp[i + 1][3] = min(dp[i + 1][3], val + (a[i] == 0 ? 2 : (a[i] & 1)));
            }
        }
    }

    long long ans = dp[n][0];
    for (int i = 0; i < 5; i++) ans = min(ans, dp[n][i]);
    cout << ans;
}