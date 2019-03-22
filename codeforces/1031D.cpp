#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int dp[2005][2005];
bool checked[2005][2005];
string matrix[2005];
int n, k;


int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            checked[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    if (matrix[0][0] == 'a') {
        dp[0][0] = 0;
    }
    else {
        dp[0][0] = 1;
    }

    for (int i = 1; i < n; i++) {
        dp[0][i] = dp[0][i - 1];
        if (matrix[0][i] != 'a') dp[0][i]++;
        dp[i][0] = dp[i - 1][0];
        if (matrix[i][0] != 'a') dp[i][0]++;
    }


    int max_ij = -1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
            if (matrix[i][j] != 'a') dp[i][j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] <= k) max_ij = max(max_ij, i + j);
        }
    }


    if (max_ij == 2 * n - 2) {
        cout << string(2 * n - 1, 'a');
        return 0;
    }

    vector<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        int j = max_ij - i;
        if (j >= n) continue;
        if (j < 0) break;
        if (dp[i][j] == k) {
            q.push_back({i, j}); 
        }
    }

    string ans;

    if (q.empty()) {
        ans += matrix[0][0];
        q.push_back({0, 0});
    }

    while (!q.empty()) {
        vector<pair<int, int>> next;
        for (char c = 'a'; c <= 'z'; c++) {
            for (auto p : q) {
                int i = p.first;
                int j = p.second;
                if (i + 1 < n && matrix[i + 1][j] == c && !checked[i + 1][j]) {
                    next.push_back({i + 1, j});
                    checked[i + 1][j] = true;
                }
                if (j + 1 < n && matrix[i][j + 1] == c && !checked[i][j + 1]) {
                    next.push_back({i, j + 1});
                    checked[i][j + 1] = true;
                }
            }

            if (next.size()) {
                ans += c;
                break;
            }
        }
        q = next;
    }

    string pre(max_ij + 1, 'a');
    cout << pre + ans << endl;
}

