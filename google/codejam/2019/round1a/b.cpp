#include <bits/stdc++.h>

using namespace std;

int t, n, m;

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

int CRT(vector<int>& coprime, vector<int>& rems) {
    int prod = 1;
    for (int i : coprime) prod *= i;
    int n = coprime.size();
    vector<int> pp(n);
    for (int i = 0; i < n; i++) {
        pp[i] = prod / coprime[i];
    }

    vector<int> inv(n);
    for (int i = 0; i < n; i++) {
        inv[i] = modinverse(pp[i], coprime[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res += ((long long)rems[i] * pp[i] * inv[i]) % prod;
        res %= prod;
    }
    return res;
}

void solve() {
    vector<int> coprime = {5, 7, 9, 11, 13, 16, 17};
    vector<int> rems(7);
    int prod = 1;
    for (int i : coprime) prod *= i;

    for (int i = 0; i < coprime.size(); i++) {
        string s;
        for (int j = 0; j < 18; j++) {
            s += to_string(coprime[i]) + ' ';
        }
        cout << s << endl;;
        cout.flush();

        int rem = 0;
        for (int j = 0; j < 18; j++) {
            int r;
            cin >> r;
            rem += r;
        }
        
        rems[i] = rem % coprime[i];
    }
    int x = CRT(coprime, rems);
    cout << x << endl;
    cout.flush();
    
    int res;
    cin >> res;
    if (res == -1) exit(0);
}

int main() {
    cin >> t >> n >> m;
    for (int i = 0; i < t; i++) {
        solve();
    }
}