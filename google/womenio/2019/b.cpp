#include <bits/stdc++.h>

using namespace std;

int solve() {
    int k;
    cin >> k;

    vector<int> m(k + 1);
    for (int i = 0; i <= k; i++) cin >> m[i];

    int ans = 0;
    bool can_hill = false;
    bool can_valley = false;
    int big = m[0];
    int small = m[0];
    for (int i = 0; i <= k; i++) {
        if (m[i] < big && can_hill) {
            ans++;
            can_hill = false;
            can_valley = false;
            big = m[i];
            small = m[i];
        }
        else if (m[i] > small && can_valley) {
            ans++;
            can_hill = false;
            can_valley = false;
            big = m[i];
            small = m[i];
        }
        else if (m[i] > big) {
            big = m[i];
            can_hill = true;
        }
        else if (m[i] < small) {
            small = m[i];
            can_valley = true;
        }
    }
    return ans - 1;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}