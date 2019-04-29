#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
const int N = 205;

const int SZ = 100005;

int inv[N];
int s[SZ];
int dp[N][SZ];

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}


int main() {
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s, s + n);

    for (int i = 0; i <= x; i++) {
        dp[0][i] = i % s[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = add(dp[i - 1][j % s[i]], mul(dp[i - 1][j], i));
        }
    }

    cout << dp[n - 1][x];
    //dp[i][j] = dp[i - 1][j % s[i]] + dp[i - 1][j] * i;
}