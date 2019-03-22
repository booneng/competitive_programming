#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class HungarianAlgorithm {

private:

    // cost matrix
    vector<vector<int>> a;
    int n, m;
    // stores potentials for row and column
    vector<int> u, v;
    // stores match per column
    vector<int> match;
    // stores path for alternating path finding algo
    vector<int> way;

public:

    HungarianAlgorithm(const vector<vector<int>>& costs) 
        : a(costs)
    {
        n = costs.size();
        m = costs[0].size();
        u = vector<int>(n + 1);
        v = vector<int>(m + 1);
        match = vector<int>(m + 1);
        way = vector<int>(m + 1);
    }   

    vector<int> GetMatch() {
        for (int i = 1; i <= n; i++) {
            match[0] = i;
            int j0 = 0;
            vector<int> minv(m + 1, INT_MAX);
            vector<bool> used(m + 1, false);

            do {
                used[j0] = true;
                int i0 = match[j0];
                int delta = INT_MAX;
                int j1;
                for (int j = 1; j <= m; j++) {
                    if (!used[j]) {
                        int cur = a[i0][j] - u[i0] - v[j];
                        if (cur < minv[j]) {
                            minv[j] = cur;
                            way[j] = j0;
                        }
                        if (minv[j] < delta) {
                            delta = minv[j];
                            j1 = j;
                        }
                    }
                }

                for (int j = 0; j <= m; j++) {
                    if (used[j]) {
                        u[match[j]] += delta;
                        v[j] -= delta;
                    }
                    else {
                        minv[j] -= delta;
                    }
                }
                j0 = j1;
            } while (match[j0] != 0);

            // if alternating path found, update the matching
            do {
                int j1 = way[j0];
                match[j0] = j1;
                j0 = j1;
            } while (j0);
        }

        vector<int> ans(n + 1);
        for (int j = 1; j <= m; j++) {
            ans[match[j]] = j;
        }
        return ans;
    }
};