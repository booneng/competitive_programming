#include <bits/stdc++.h>

using namespace std;

void solve() {
    string ans;
    vector<int> nums(119);
    for (int i = 0; i < 119; i++) {
        nums[i] = i;
    }

    vector<bool> used(5);
    for (int t = 0; t < 4; t++) {
        vector<int> idxs[5];
        int n = nums.size();
        int target = n / (5 - t) + 1;
        for (int i = 0; i < n; i++) {
            cout << (nums[i] * 5 + t + 1) << endl;
            cout.flush();
            string c;
            cin >> c;
            if (c == "N") exit(0);
            idxs[c[0] - 'A'].push_back(nums[i]);
        }
        for (int i = 0; i < 5; i++) {
            if (!used[i] && idxs[i].size() != target) {
                ans += 'A' + i;
                used[i] = true;
                nums = idxs[i];
                break;
            }
        }
    }

    vector<bool> seen(5);
    for (int i = 0; i < 4; i++) {
        seen[ans[i] - 'A'] = true;
    }
    for (int i = 0; i < 5; i++) {
        if (!seen[i]) ans += 'A' + i;
    }
    cout << ans << endl;
    cout.flush();
    string res;
    cin >> res;
    if (res == "N") exit(0);
}

int main() {
    int t, f;
    cin >> t >> f;
    for (int i = 1; i <= t; i++) {
        solve();
    }
}