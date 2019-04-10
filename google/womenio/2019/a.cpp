#include <bits/stdc++.h>

using namespace std;

void solve() {
    int r, c, k;
    cin >> r >> c >> k;
    if (k == r * c - 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << "POSSIBLE" << endl;
    vector<vector<char>> ans(r, vector<char>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i * c + j + 1 <= k) {
                ans[i][j] = 'N';
            }
            else {
                ans[i][j] = 'S';
            }
        }
    }

    if (c == 1) {
        if (ans[r - 1][c - 1] == 'S') ans[r - 1][c - 1] = 'N';
    }
    else {
        for (int j = 0; j < c; j++) {
            if (ans[r - 1][j] == 'S') ans[r - 1][j] = 'E';
        }
        ans[r - 1][c - 1] = 'W';
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
