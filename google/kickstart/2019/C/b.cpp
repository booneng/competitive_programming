#include <bits/stdc++.h>

using namespace std;

int solve() {
    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    vector<map<int, int>> nums(r);
    vector<int> rights(r);
    for (int left = 0; left < c; left++) {
        for (int i = 0; i < r; i++) {
            if (rights[i] == left) {
                nums[i][grid[i][left]]++;
                rights[i]++;
            }
            int small = nums[i].begin()->first;
            int big = nums[i].rbegin()->first;

            while (rights[i] < c && (grid[i][rights[i]] - small <= k) && (big - grid[i][rights[i]] <= k)) {
                int num = grid[i][rights[i]];
                nums[i][num]++;
                small = min(small, num);
                big = max(big, num);
                rights[i]++;
            }
        }

        stack<int> lens;
        stack<int> idxs;
        for (int i = 0; i < r; i++) {
            int width = rights[i] - left;
            while (!lens.empty() && width <= lens.top()) {
                int len = lens.top();
                int pos = idxs.top();
                lens.pop();
                idxs.pop();
                ans = max(ans, len * (i - pos));
            }
            
            lens.push(width);
            idxs.push(i);
        }

        while (!lens.empty()) {
            int len = lens.top();
            int pos = idxs.top();
            lens.pop();
            idxs.pop();
            ans = max(ans, len * (r - pos));
        }

        for (int i = 0; i < r; i++) {
            nums[i][grid[i][left]]--;
            if (nums[i][grid[i][left]] == 0) {
                nums[i].erase(grid[i][left]);
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