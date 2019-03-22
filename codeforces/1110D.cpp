#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<int> cnts(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnts[a]++;
    }

    int dp[1000005][3][3];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3 && l <= cnts[i] - j - k; l++) {
                    dp[i][k][l] = max(dp[i][k][l], dp[i - 1][j][k] + l + (cnts[i] - j - k - l) / 3);
                }
            }
        }
    }
    cout << dp[m][0][0];
}