#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n, s;
    cin >> n >> s;
    vector<int> types(n);
    for (int i = 0; i < n; i++) {
        cin >> types[i];
    }

    int ans = 0;
    for (int l = 0; l < n; l++) {
        unordered_map<int, int> cnts;
        int score = 0;
        for (int r = l; r < n; r++) {
            if (cnts[types[r]] == s) {
                score -= s;
            }
            else if (cnts[types[r]] < s) {
                score++;
            }

            cnts[types[r]]++;
            ans = max(ans, score);
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