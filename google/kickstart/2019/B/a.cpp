#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n, q;
    cin >> n >> q;
    
    string s;
    cin >> s;

    vector<vector<int>> cnts(26, vector<int>(n + 1));
    for (int j = 1; j <= n; j++) {
        int idx = s[j - 1] - 'A';
        for (int i = 0; i < 26; i++) {
            cnts[i][j] = cnts[i][j - 1];
        }
        cnts[idx][j]++;
    }

    int ans = 0;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int odd = 0;
        for (int j = 0; j < 26; j++) {
            int cnt = cnts[j][r] - cnts[j][l - 1];
            if (cnt % 2) odd++;
        }
        int len = r - l + 1;
        if (odd == 0) ans++;
        else if (odd == 1 && len % 2) ans++;
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