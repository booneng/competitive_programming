#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int maxc = c[l];
            int maxd = d[l];
            for (int i = l; i <= r; i++) {
                maxc = max(maxc, c[i]);
                maxd = max(maxd, d[i]);
            }
            if (abs(maxc - maxd) <= k) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}