#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<int> xs(n);
    for (int i = 0; i < n; i++) {
        cin >> xs[i];
    }
    n++;
    xs.push_back(1000000000);

    vector<int> ys(m);

    for (int i = 0; i < m; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        if (x1 == 1) {
            ys.push_back(x2);
        }
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    m = ys.size();
    int ans = m;
    int cur = 0;
    for (int i = 0; i <= n; i++) {
        int end = xs[i];
        while (cur < m && ys[cur] < end) {
            cur++;
        }
        ans = min(ans, i + m - cur);
    }
    cout << ans;
}