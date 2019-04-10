#include <bits/stdc++.h>

using namespace std;

int n;

int solve() {
    cin >> n;

    int minx = INT_MAX;
    int maxx = 0;

    int miny = INT_MAX;
    int maxy = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }

    int turns = max((maxx - minx + 1) / 2, (maxy - miny + 1) / 2);
    return turns;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}