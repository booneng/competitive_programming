#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

const int inf = 300 * 2;
int r, c;

bool check(int k, vector<vector<int>>& distances) {

    int plus_max = inf;
    int plus_min = -inf;
    int minus_max = inf;
    int minus_min = -inf;
    bool can = true;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (distances[i][j] > k) {
                plus_max = min(plus_max, i + j + k);
                plus_min = max(plus_min, i + j - k);
                minus_max = min(minus_max, i - j + k);
                minus_min = max(minus_min, i - j - k);
                can = false;
            }
        }
    }

    if (can) return true;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int plus = i + j;
            int minus = i - j;

            if (plus >= plus_min && plus <= plus_max && minus >= minus_min && minus <= minus_max)
                return true;
        }
    }
    return false;
}

int solve() {
    cin >> r >> c;
    vector<string> grid(r);
    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> distances(r, vector<int>(c, r * c));

    queue<pair<int, int>> q;


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '1') {
                q.push({i, j});
                distances[i][j] = 0;
            }
        }
    }

    int dist = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nr = cr + dy[dir];
                int nc = cc + dx[dir];

                if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
                if (distances[nr][nc] > dist) {
                    distances[nr][nc] = dist;
                    q.push({nr, nc});
                }
            }
        }
        dist++;
    }

    int res = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res = max(res, distances[i][j]);
        }
    }


    int left = 0;
    int right = res;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid, distances)) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}