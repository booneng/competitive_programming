#include <bits/stdc++.h>

using namespace std;

const char B = 'B';
const char W = 'W';

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

string grid[25];
string grid_2[105];

bool used[25][25];
bool visited[25][25];

int r, c;
int ans;

int calculate(int i, int j) {
    if (i >= r || i < 0 || j >= c || j < 0) return 0;
    if (!used[i][j]) return 0;
    if (visited[i][j]) return 0;
    visited[i][j] = true;
    return 1 + calculate(i + 1, j) + calculate(i - 1, j) + calculate(i, j + 1) + calculate(i, j - 1);
}

int solve() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < 4 * r; i++) {
        grid_2[i] = string(4 * c, '.');
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    grid_2[4 * i + x][4 * j + y] = grid[i][j];
                }
            }
        }
    }

    int ans = 0;
    for (int i1 = 0; i1 < 4 * r - r + 1; i1++) {
        for (int j1 = 0; j1 < 4 * c - c + 1; j1++) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    used[i][j] = false;
                    visited[i][j] = false;
                }
            }
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] == grid_2[i1 + i][j1 + j]) {
                        used[i][j] = true;
                    }
                }
            }

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (!visited[i][j] && used[i][j]) {
                        int sz = calculate(i, j);
                        ans = max(ans, sz);
                    }
                }
            }
        }
    }


    return ans;

}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}