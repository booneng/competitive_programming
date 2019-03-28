/* Problem URL: https://oj.uz/problem/view/APIO14_sequence
   Tags: dp, convex hull optimization */

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;

const int N = 100005;

long long a[N];

struct Line {
    long long a, b;
    int idx;

    long long GetCost(long long x) {
        return a * x + b;
    }

    double Intersect(const Line& l) {
        return (double)(b - l.b) / (l.a - a);
    }

};

bool Check(Line& l1, Line& l2, Line& l3) {
    return (l3.b - l2.b) * (l1.a - l2.a) <= (l2.b - l1.b) * (l2.a - l3.a);
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> sums(n + 1);
    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + a[i];
    }

    vector<long long> dp1(n + 1);
    vector<long long> dp2(n + 1);
    vector<vector<int>> splits(k + 1, vector<int>(n + 1));

    for (int i = 1; i <= k; i++) {
        deque<Line> lines;
        lines.push_back({sums[i], dp1[i] - sums[i] * sums[i], i});
        for (int j = i + 1; j <= n; j++) {
            while (lines.size() > 1 && lines[0].GetCost(sums[j]) <= lines[1].GetCost(sums[j])) {
                lines.pop_front();
            }

            dp2[j] = lines[0].GetCost(sums[j]);
            splits[i][j] = lines[0].idx;

            Line l({sums[j], dp1[j] - sums[j] * sums[j], j});
            while (lines.size() > 1 && Check(lines[lines.size() - 2], lines.back(), l)) {
                lines.pop_back();
            }
            lines.push_back(l);
        }
        dp1 = dp2;
    }

    cout << dp2[n] << endl;
    stack<int> st;
    for (int i = k, j = n; i > 0; i--) {
        j = splits[i][j];
        st.push(j);
    }

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
}
