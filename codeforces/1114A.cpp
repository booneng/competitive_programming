#include <vector>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> a;
    a.push_back(c[0]);
    for (int i = 1; i < n; i++) {
        if (c[i] != a.back()) a.push_back(c[i]);
    }

    n = a.size();
    vector<vector<int>> dp(n, vector<int>(n, n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    for (int d = 1; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            int j = i + d;
            dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
            if (a[i] == a[j]) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + 1);
            }
        }
    }


    cout << dp[0][n - 1];
}