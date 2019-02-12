#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105;
int a[N];
long long ans[N][N];
long long dp[2][N][N][N];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(ans, -1, sizeof(ans));

    for (int i = 0; i <= n; i++) {
        ans[i][i] = 0;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[0][i][j][0] = 0;
            dp[1][i][j][0] = 0;
            for (int k = 1; k <= n; k++) {
                dp[0][i][j][k] = -(1LL << 60);
                dp[1][i][j][k] = -(1LL << 60);
            }
        }
    }

    for (int d = 1; d <= n; d++) {
        for (int i = 0; i <= n - d; i++) {
            int j = i + d;
            for (int cnt = 1; cnt <= j - i; cnt++) {
                for (int mid = i; mid < j; mid++) {
                    if (s[mid] == '1') {
                        long long &res = dp[1][i][j][cnt];
                        res = max(res, ans[i][mid] + dp[1][mid + 1][j][cnt - 1]);
                    }
                    else {
                        long long &res = dp[0][i][j][cnt];
                        res = max(res, ans[i][mid] + dp[0][mid + 1][j][cnt - 1]);
                    }
                }

                ans[i][j] = max(ans[i][j], dp[0][i][j][cnt] + a[cnt - 1]);
                ans[i][j] = max(ans[i][j], dp[1][i][j][cnt] + a[cnt - 1]);
            }
        }
    }
    cout << ans[0][n];
}