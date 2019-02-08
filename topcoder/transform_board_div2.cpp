#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>

using namespace std;

class TransformBoardDiv2 {

public:
    int n;
    int m;
    bool seen[70000];
    int prev[70000];
    int code[70000];
    int Convert(const vector<string>& grid) {
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#') {
                    ret += 1 << (i * m + j);
                }
            }
        }
        return ret;
    }

    vector<int> getOperations(vector<string> start, vector<string> target) {
        memset(seen, 0, sizeof(seen));
        n = start.size();
        m = start[0].size();
        int first = Convert(start);
        queue<int> q;
        q.push(first);
        seen[first] = true;
        int end = Convert(target);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == end) break;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int ni = 0; ni < n; ni++) {
                        for (int nj = 0; nj < m; nj++) {
                            if (i + j < ni + nj) {
                                if (i == ni || j == nj) {
                                    int next = cur;
                                    int i1 = 1 << (i * m + j);
                                    int i2 = 1 << (ni * m + nj);
                                    bool v1 = next & i1;
                                    bool v2 = next & i2;
                                    if (v1 == v2) {
                                        next &= ~i2;
                                    }
                                    else {
                                        next |= i2;
                                    }
                                    next &= ~i1;
                                    if (!seen[next]) {
                                        seen[next] = true;
                                        prev[next] = cur;
                                        code[next] = i * 1000000 + j * 10000 + ni * 100 + nj;
                                        q.push(next);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        vector<int> ans;
        if (seen[end]) {
            while (end != first) {
                ans.push_back(code[end]);
                end = prev[end];
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
        else {
            return {-1};
        }
    }
};
