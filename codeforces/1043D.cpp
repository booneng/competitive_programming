#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        pos[a[1][i]] = i;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = pos[a[i][j]];
        }
    }

    vector<int> reach(n + 1);
    for (int i = 1; i <= n; i++) {
        reach[i] = n;
    }

    for (int i = 1; i <= m; i++) {
        int right = 1;
        for (int j = 1; j <= n; j++) {
            if (right < j) right++;
            while (right <= n && a[i][right] == a[i][right + 1] - 1) {
                right++;
            }
            reach[a[i][j]] = min(reach[a[i][j]], right - j + 1);
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += reach[i];
    }
    cout << ans;
}