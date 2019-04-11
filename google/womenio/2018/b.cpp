#include <bits/stdc++.h>

using namespace std;

long long solve() {
    int l;
    cin >> l;

    map<long long, long long> levels;
    for (int i = 0; i < l; i++) {
        long long n, e;
        cin >> n >> e;
        levels[e] = n;
    }

    long long cnt = 0;
    long long highest = 0;
    for (auto it : levels) {
        long long n = it.second;
        long long can_manage = n * it.first;

        cnt = max(0LL, cnt - can_manage);
        cnt += n;
        highest = max(highest, it.first);
    }

    return max(cnt, highest + 1);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}