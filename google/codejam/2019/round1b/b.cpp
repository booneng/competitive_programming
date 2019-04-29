#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> rings(7);
    vector<long long> cnts(10);

    for (int i = 1; i <= 7; i++) {
        if (i == 3) continue;
        cout << i << endl;
        cout.flush();
        cin >> cnts[i];
    }

    rings[1] = (cnts[7] - cnts[6]) / 64;
    rings[2] = cnts[2] - cnts[1] - 2 * rings[1];
    rings[5] = cnts[5] - cnts[4] - 16 * rings[1];

    long long d1 = cnts[6] - cnts[5];
    long long d2 = cnts[6] - cnts[3] - 56 * rings[1] - 2 * rings[3] - ;




    for (int i = 1; i <= 6; i++) {
        cout << rings[i] << ' ';
    }
    cout << endl;
    cout.flush();

}

int main() {
    int t, w;
    cin >> t >> w;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}