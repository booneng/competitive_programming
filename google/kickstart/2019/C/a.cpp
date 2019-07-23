#include <bits/stdc++.h>

using namespace std;


pair<int, int> solve() {
    int n, r, c, si, sj;
    cin >> n >> r >> c >> si >> sj;
    si--;
    sj--;
    unordered_set<int> visited;

    visited.insert(si * c + sj);
    string instructions;
    cin >> instructions;
    for (char ins : instructions) {
        int di, dj;
        if (ins == 'N') {
            di = -1;
            dj = 0;
        }
        else if (ins == 'S') {
            di = 1;
            dj = 0;
        }
        else if (ins == 'E') {
            di = 0;
            dj = 1;
        }
        else {
            di = 0;
            dj = -1;
        }

        int id = si * c + sj;
        while (visited.count(id)) {
            si += di;
            sj += dj;
            id = si * c + sj;
        }
        visited.insert(id);
    }
    return {si + 1, sj + 1};
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        auto res = solve();
        cout << "Case #" << i << ": " << res.first << ' ' << res.second << endl;
    }
}