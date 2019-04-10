#include <bits/stdc++.h>

using namespace std;

const int N = 505;
double dp[N][N];

int main() {
    int t;
    cin >> t;
    cout << fixed << setprecision(10);

    dp[0][0] = 0;
    dp[0][1] = 2;
    dp[1][0] = 2;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (x + y <= 1) continue;
            if (x == 0) {
                dp[x + 1][y - 1] = dp[x][y - 1] / 2 + dp[x + 1][y - 2] / 2 + 1;
                dp[x][y] = 2 * dp[x][y - 1] / 3 + dp[x + 1][y - 1] / 3 + 2;
            }
            else if (y == 0) {
                dp[x][y] = 2 * dp[x - 1][y] / 3 + dp[x - 1][y + 1] / 3 + 2;
            }
            else {
                dp[x][y] = dp[x - 1][y] / 2 + dp[x][y - 1] / 2 + 1;
            }
        }
    }
    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        cout << "Case #" << i << ": " << dp[x][y] << endl;
    }
}