#include <bits/stdc++.h>

using namespace std;

pair<int, int> GetRange(int package, int r) {
    int right = (10 * package) / (9 * r);
    int left = (10 * package) / (11 * r);

    if (10 * package > 11 * r * left) left++;
    return {left, right};
}

int solve(ifstream& cin, ofstream& cout) {
    int n, p;
    cin >> n >> p;

    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    vector<vector<int>> packages(n, vector<int>(p));
    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> ranges(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> packages[i][j];
            ranges[i].push(GetRange(packages[i][j], r[i]));
        }
    }

    int ans = 0;
    while (true) {
        for (int i = 0; i < n; i++) if (ranges[i].empty()) return ans;

        int left = ranges[0].top().first;
        int right = ranges[0].top().second;
        bool can = true;
        for (int i = 0; i < n; i++) {
            int cleft = ranges[i].top().first;
            int cright = ranges[i].top().second;
            if (cleft > right) {
                can = false;
                break;
            }
            else if (cright < left) {
                can = false;
                break;
            }
            left = max(left, ranges[i].top().first);
            right = max(right, ranges[i].top().second);
        }
        if (can) {
            ans++;
            for (int i = 0; i < n; i++) {
                ranges[i].pop();
            }
        }
        else {
            int smallest = 1000000;
            for (int i = 0; i < n; i++) {
                smallest = min(smallest, ranges[i].top().second);
            }

            for (int i = 0; i < n; i++) {
                if (ranges[i].top().second == smallest) ranges[i].pop();
            }
        }
    }


}

int main() {
    ifstream cin("B-large-practice.in");
    ofstream cout("test.out");
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve(cin, cout) << endl;
    }
}