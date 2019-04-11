#include <bits/stdc++.h>

using namespace std;

const int K = 105;
int d[K];

int k;

int solve() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> d[i];
    }

    sort(d, d + k);

    int ans = 0;
    for (int i = 0; i < k; i++) {
        int pos = i / 2;
        int diff = pos - d[i];
        ans += diff * diff;
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