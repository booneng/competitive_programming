#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

const int N = 200005;

int facs[N];
int invs[N];

int probs[N];

int p[N];
int q[N];

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

int choose(int n, int r) {
    return mul(facs[n], mul(invs[n - r], invs[r]));
}

int main() {
    int b, w;
    cin >> b >> w;

    facs[0] = 1;
    for (int i = 1; i <= b + w; i++) {
        facs[i] = mul(facs[i - 1], i);
    }

    invs[b + w] = powmod(facs[b + w], mod - 2);

    for (int i = b + w - 1; i >= 0; i--) {
        invs[i] = mul(invs[i + 1], i + 1);
    }

    int two_inv = powmod(2, mod - 2);
    probs[0] = 1;
    for (int i = 1; i <= b + w; i++) {
        probs[i] = mul(probs[i - 1], two_inv);
    }

    for (int i = 0; i <= b + w; i++) {
        p[i] = 0;
        q[i] = 0;
    }

    for (int i = b; i <= b + w; i++) {
        p[i] = add(p[i - 1], mul(choose(i - 1, b - 1), probs[i]));
    }

    for (int i = w; i <= b + w; i++) {
        q[i] = add(q[i - 1], mul(choose(i - 1, w - 1), probs[i]));
    }

    for (int i = 1; i <= b + w; i++) {
        cout << mul(add(1, add(mod - p[i - 1], q[i - 1])), probs[1]) << endl;
    }



}