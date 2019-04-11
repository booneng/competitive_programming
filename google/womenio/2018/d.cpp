#include <bits/stdc++.h>

using namespace std;

const int N = 105;
double dp[N][N][N];

void solve() {
    int n = 100;
    dp[0][0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                dp[i][j][k] = 0;
            }
        }
    }

    for (int zero = 0; zero <= n; zero++) {
        for (int one = 0; one <= n; one++) {
            for (int two = 0; two <= n; two++) {
                if (two + one + zero > n || two + one + zero == 0) continue;
                double remaining = two + 2 * one + 3 * zero;

                double n0 = 3 * zero;
                double n1 = 2 * one;
                double n2 = two;

                // choose two
                if (two > 0) {
                    dp[two][one][zero] += n2 / remaining * (1 + dp[two - 1][one][zero]);
                }

                // choose one
                if (one > 0) {
                    dp[two][one][zero] += (n1 / remaining) * (1.0 / (remaining - 1)) * (1 + dp[two][one - 1][zero]);
                }

                if (one > 1) {
                    dp[two][one][zero] += (n1 / remaining) * ((n1 - 2) / (remaining - 1)) * (1 + dp[two + 2][one - 2][zero]);
                }

                // choose zero
                if (zero > 0) {
                    dp[two][one][zero] += (n0 / remaining) * (2 / (remaining - 1)) * (1 / (remaining - 2)) * (1 + dp[two][one][zero - 1]);
                }

                if (zero > 1) {
                    dp[two][one][zero] += (n0 / remaining) * ((n0 - 3) / (remaining - 1)) * (1 + dp[two][one + 2][zero - 2]);
                    dp[two][one][zero] += (n0 / remaining) * (2 / (remaining - 1)) * ((n0 - 3) / (remaining - 2)) * (1 + dp[two + 1][one + 1][zero - 2]);
                }
                
                // choose one and zero
                if (one > 0 && zero > 0) {
                    dp[two][one][zero] += 2 * (n0 / remaining) * (n1 / (remaining - 1)) * (1 + dp[two + 1][one][zero - 1]);
                    dp[two][one][zero] += (n0 / remaining) * (2 / (remaining - 1)) * (n1 / (remaining - 2)) * (1 + dp[two + 2][one - 1][zero - 1]);
                }

                // choose one and two
                if (one > 0 && two > 0)
                    dp[two][one][zero] += (n1 / remaining) * (n2 / (remaining - 1)) * (2 + dp[two][one - 1][zero]);

                // choose zero and two
                if (zero > 0 && two > 0) {
                    // 0, 2
                    dp[two][one][zero] += (n0 / remaining) * (n2 / (remaining - 1)) * (2 + dp[two - 1][one + 1][zero - 1]);
                    // 0, 0, 2
                    dp[two][one][zero] += (n0 / remaining) * (2 / (remaining - 1)) * (n2 / (remaining - 2)) * (2 + dp[two][one][zero - 1]);
                }

            }
        }
    }
}

int main() {
    cout << fixed << setprecision(15);
    int t;
    cin >> t;
    solve();
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        cout << "Case #" << i << ": " << dp[0][0][n] << endl;
    }
}