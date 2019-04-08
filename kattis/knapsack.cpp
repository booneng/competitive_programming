#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

const int N = 2005;
const int C = 2005;

int v[N];
int w[N];

int dp[N][C];

int main() {
    int c;
    double tmp;
    int n;
    while (cin >> tmp >> n) {
        c = tmp;

        for (int i = 1; i <= n; i++) {
            cin >> v[i] >> w[i];
        }

        for (int cap = 0; cap <= c; cap++) {
            dp[0][cap] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int cap = 1; cap <= c; cap++) {
                dp[i][cap] = dp[i - 1][cap];
                if (w[i] <= cap) {
                    if (dp[i - 1][cap - w[i]] + v[i] > dp[i][cap]) {
                        dp[i][cap] = dp[i - 1][cap - w[i]] + v[i];
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = n; i >= 1; i--) {
            if (dp[i][c] == dp[i - 1][c]) continue;
            ans.push_back(i - 1);
            c -= w[i];
        }

        cout << ans.size() << endl;
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
}