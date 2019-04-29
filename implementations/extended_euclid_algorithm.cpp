#include <bits/stdc++.h>

using namespace std;

int extendedEuclidean(int x, int y, int& alpha, int &beta) {
    if (y == 0) {
        alpha = 1;
        beta = 0;
        return x;
    }

    int d = extendedEuclidean(y, x % y, alpha, beta);
    int tmp = alpha;
    alpha = beta;
    beta = tmp - (x / y) * beta;
    return d;
}

int modinverse(int a, int m) {
    int alpha, beta;
    // alpha * x + beta * m = g
    int g = extendedEuclidean(a, m, alpha, beta);

    if (g != 1) {
        return -1;
    }
    if (alpha < 0) alpha += m;
    return alpha;
}

int main() {
    int alpha, beta;
    int mod = 1000000007;
    // finding inverse of i % mod for each i
    for (int i = 1; i < 10000; i++) {
        cout << i << ' ' << modinverse(i, mod) << ' ' << ((long long)i * modinverse(i, mod)) % mod <<  endl;
    }
}
