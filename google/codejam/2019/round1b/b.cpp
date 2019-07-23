#include <bits/stdc++.h>

using namespace std;

long long pow2[70];

void solve() {
    vector<long long> cnts(10);
    for (long long i = 1; i < 6; i++) {
        cout << i * 63 << endl;
        cout.flush();
        cin >> cnts[i];
    }
    cout << 1 << endl;
    cout.flush();
    cin >> cnts[0];

    vector<int> rings(10);
    // cnts[5] = r6 * 2^52
    rings[6] = cnts[5] / pow2[52];
    //cnts[4] = r5 * 2^50 + r6 * 2^42
    rings[5] = (cnts[4] - rings[6] * pow2[42]) / pow2[50];
    //cnts[3] = r4 * 2^47 + r5 * 2^37 + r6 * 31
    rings[4] = (cnts[3] - rings[5] * pow2[37] - rings[6] * pow2[31]) / pow2[47];
    rings[3] = (cnts[2] - rings[4] * pow2[31] - rings[5] * pow2[25] - rings[6] * pow2[21]) / pow2[42];
    rings[2] = (cnts[1] - rings[3] * pow2[21] - rings[4] * pow2[15] - rings[5] * pow2[12] - rings[6] * pow2[10]) / pow2[31];
    rings[1] = (cnts[0] - rings[2] - rings[3] - rings[4] - rings[5] - rings[6]) / 2;

    for (int i = 1; i <= 6; i++) {
        cout << rings[i] << ' ';
    }
    cout << endl;
    cout.flush();
    int res;
    cin >> res;
}

int main() {
    pow2[0] = 1;
    for (int i = 1; i < 70; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }
    int t, w;
    cin >> t >> w;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}
