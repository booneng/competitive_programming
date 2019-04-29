#include <bits/stdc++.h>

using namespace std;

pair<int, int> solve() {
    int p, q;
    cin >> p >> q;

    vector<int> rowsup(q + 1);
    vector<int> rowsdown(q + 1);
    vector<int> colsright(q + 1);
    vector<int> colsleft(q + 1);

    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        char dir;
        cin >> dir;

        if (dir == 'N') {
            rowsup[y + 1]++;
        }
        else if (dir == 'S') {
            rowsdown[y - 1]++;
        }
        else if (dir == 'E') {
            colsright[x + 1]++;
        }
        else {
            colsleft[x - 1]++;
        }
    }



    vector<int> sumsrow(q + 1);
    for (int i = 1; i <= q; i++) {
        rowsup[i] += rowsup[i - 1];
    }

    for (int i = q - 1; i >= 0; i--) {
        rowsdown[i] += rowsdown[i + 1];
    }

    for (int i = 0; i <= q; i++) {
        sumsrow[i] = rowsup[i] + rowsdown[i];
    }

    vector<int> sumscol(q + 1);
    for (int i = 1; i <= q; i++) {
        colsright[i] += colsright[i - 1];
    }

    for (int i = q - 1; i >= 0; i--) {
        colsleft[i] += colsleft[i + 1];
    }

    for (int i = 0; i <= q; i++) {
        sumscol[i] = colsright[i] + colsleft[i];
    }

    int m1 = 0;
    int m2 = 0;
    int row_target = 0;
    int col_target = 0;
    for (int i = 0; i <= q; i++) {
        if (sumsrow[i] > m1) {
            row_target = i;
            m1 = sumsrow[i];
        }
        if (sumscol[i] > m2) {
            col_target = i;
            m2 = sumscol[i];
        }
    }
    return {col_target, row_target};
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        auto p = solve();
        cout << "Case #" << i << ": " << p.first << ' ' << p.second << endl;
    }
}