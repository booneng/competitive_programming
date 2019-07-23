#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000003;

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int add(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

int powmod(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        p >>= 1;
    }
    return res;
}

int main() {
    int q;
    cin >> q;
    int inv2 = powmod(2, mod - 2);
    for (int i = 0; i < q; i++) {
        int x, d, n;
        cin >> x >> d >> n;

        int ans = add(mul(n, x), mul(d, mul(inv2, mul(n, n - 1))));
        cout << ans << endl;
    }
}