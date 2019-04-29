#include <bits/stdc++.h>

using namespace std;

int rowcnt[25];
int colcnt[25];
int diag1[55];
int diag2[55];

bool used[25][25];

void solve() {
    int r, c;
    cin >> r >> c;
    if (r * c <= 9) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << "POSSIBLE" << endl;

    memset(rowcnt, 0, sizeof(rowcnt));
    memset(colcnt, 0, sizeof(colcnt));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            used[i][j] = false;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            rowcnt[i]++;
            colcnt[j]++;
            diag1[i + j]++;
            diag2[i - j + c]++;
        }
    }

    int prevr = -1;
    int prevc = -1;
    int prevd1 = -1;
    int prevd2 = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int most = 0;
            int row = 0;
            int col = 0;
            for (int k = 0; k < r; k++) {
                for (int l = 0; l < c; l++) {
                    if (used[k][l] || k == prevr || l == prevc || k + l == prevd1 || k - l + c == prevd2) continue;
                    int cost = rowcnt[k] + colcnt[l] + diag1[k + l] + diag2[k - l + c];
                    if (cost > most) {
                        most = cost;
                        row = k;
                        col = l;
                    }
                }
            }

            used[row][col] = true;
            rowcnt[row]--;
            colcnt[col]--;
            diag1[row + col]--;
            diag2[row - col + c]--;

            prevr = row;
            prevc = col;
            prevd1 = row + col;
            prevd2 = row - col + c;
            cout << row + 1 << ' ' << col + 1 << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}