/* This is for solving dynamic programming recurrence relations
such as fibonacci sequence f(n) = f(n - 1) + f(n - 2) but for very
large n */

#include <iostream>
#include <vector>

using namespace std;

void MatrixMult(vector<vector<long long>>& a, vector<vector<long long>>& b) {
    int n = a.size();
    vector<vector<long long>> tmp(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                tmp[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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
    vector<vector<long long>> fib(2, vector<long long>(2));
    fib[0][1] = 1;
    fib[1][0] = fib[1][1] = 1;

    // 1000th fibonacci number
    long long n = 30;

    MatrixPower(fib, n - 2);
    long long ans = fib[1][0] + fib[1][1];
    cout << ans;
}