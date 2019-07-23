#include <bits/stdc++.h>

using namespace std;

int r, c;
unordered_map<string, int> dp;

bool valid(vector<string>& grid, int i, int j, bool vert) {
    if (vert) {
        for (int k = i; k < r; k++) {
            if (grid[k][j] == '#') return false;
            if (grid[k][j] == 'x') break;
        }
        for (int k = i; k >= 0; k--) {
            if (grid[k][j] == '#') return false;
            if (grid[k][j] == 'x') break;
        }
    }
    else {
        for (int k = j; k < c; k++) {
            if (grid[i][k] == '#') return false;
            if (grid[i][k] == 'x') break;
        }
        for (int k = j; k >= 0; k--) {
            if (grid[i][k] == '#') return false;
            if (grid[i][k] == 'x') break;
        }
    }

    return true;
}

pair<int, int> move(vector<string>& grid, int i, int j, bool vert) {
    int left;
    int right;
    if (vert) {
        left = i, right = i;
        for (int k = i; k < r; k++) {
            if (grid[k][j] == 'x') break;
            grid[k][j] = 'x';
            right = k;
        }
        for (int k = i - 1; k >= 0; k--) {
            if (grid[k][j] == 'x') break;
            grid[k][j] = 'x';
            left = k;
        }
    }
    else {
        left = j, right = j;
        for (int k = j; k < c; k++) {
            if (grid[i][k] == 'x') break;
            grid[i][k] = 'x';
            right = k;
        }

        for (int k = j - 1; k >= 0; k--) {
            if (grid[i][k] == 'x') break;
            grid[i][k] = 'x';
            left = k;
        }
    }
    return {left, right};
}

void unmove(vector<string>& grid, bool vert, int left, int right, int i, int j) {
    for (int k = left; k <= right; k++) {
        if (vert) {
            grid[k][j] = '.';
        }
        else {
            grid[i][k] = '.';
        }
    }
}

string stringy(vector<string>& grid) {
    string res;
    for (string& s : grid) {
        res += s;
    }
    return res;
}

int dfs(vector<string>& grid, bool first = false) {
    string s = stringy(grid);
    if (dp.find(s) != dp.end()) return dp[s];
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '.') {
                for (int o = 0; o < 2; o++) {
                    if (valid(grid, i, j, o)) {
                        pair<int, int> steps = move(grid, i, j, o);
                        if (!dfs(grid)) ans++;
                        unmove(grid, o, steps.first, steps.second, i, j);
                        if (!first && ans) {
                            dp[s] = ans;
                            return true;
                        }
                    }
                }
            }
        }
    }
    dp[s] = ans;
    return ans;
}

int solve() {
    cin >> r >> c;
    dp.clear();
    vector<string> grid(r);
    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }

    return dfs(grid, true);
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}