#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

long long n;
int m;

void MatrixMult(vector<vector<long long>>& a, vector<vector<long long>>& b) {
    vector<vector<long long>> tmp(m, vector<long long>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < m; k++) {
                tmp[i][j] += a[i][k] * b[k][j];
                if (tmp[i][j] >= mod) {
                    tmp[i][j] %= mod;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = tmp[i][j];
        }
    }
}

void MatrixPower(vector<vector<long long>>& a, long long n) {
    vector<vector<long long>> tmp = a;
    n--;
    while (n) {
        if (n & 1) {
            MatrixMult(a, tmp);
        }
        n >>= 1;
        MatrixMult(tmp, tmp);
    }
}

int main() {
    cin >> n >> m;
    if (n < m) {
        cout << 1;
        return 0;
    }

    vector<vector<long long>> ans(m, vector<long long>(m, 0));

    for (int i = 0; i < m - 1; i++) {
        ans[i][i + 1] = 1;
    }
    ans[m - 1][0] = 1;
    ans[m - 1][m - 1] = 1;

    MatrixPower(ans, n - m + 1);
    long long res = 0;
    for (int i = 0; i < m; i++) {
        res += ans[m - 1][i];
        if (res >= mod) res -= mod;
    }
    cout << res;
}