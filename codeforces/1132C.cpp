#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    int l[5005];
    int r[5005];

    int sections[5005];

    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
    }

    for (int i = 1; i <= n; i++) sections[i] = 0;

    for (int i = 0; i < q; i++) {
        for (int j = l[i]; j <= r[i]; j++) {
            sections[j]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < q; i++) {
        int cpy[5005];
        for (int j = 1; j <= n; j++) {
            cpy[j] = sections[j];
        }

        for (int j = l[i]; j <= r[i]; j++) {
            cpy[j]--;
        }

        int ones[5005];
        ones[0] = 0;
        for (int j = 0; j < n; j++) {
            ones[j + 1] = ones[j] + (cpy[j + 1] == 1 ? 1 : 0);
        }

        int removal = 1e9;
        for (int j = 0; j < q; j++) {
            if (j == i) continue;
            removal = min(removal, ones[r[j]] - ones[l[j] - 1]);
        }

        int res = 0;
        for (int j = 1; j <= n; j++) {
            res += cpy[j] > 0 ? 1 : 0;
        }
        res -= removal;
        ans = max(ans, res);
    }
    cout << ans;
}