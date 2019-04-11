#include <bits/stdc++.h>

using namespace std;

class OrthogonalProjections {

public:
    vector<int> generate(int n) {
        if (n == 1) {
            return {0, 0};
        }
        else if (n == 2) {
            return {0, 0, 1, 1};
        }
        else if (n == 4 || n % 2 == 0) {
            return {};
        }

        n /= 2;
        vector<int> ans;

        int t = 1;
        while ((t + 1) * (t + 1) < n) t++;

        for (int i = 0; i < t; i++) {
            ans.push_back(0);
            ans.push_back(i);
        }

        int cur = 0;
        ans.push_back(1);
        ans.push_back(0);

        n -= 1 + t;
        while (n) {
            int step = min(n, t);
            cur += step;
            n -= step;
            ans.push_back(1);
            ans.push_back(cur);
        }

        return ans;
    }
};
