#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }

    double ans = a[n - 1] / n;

    for (int i = 0; i < n; i++) {
        double add = min((double)m - (n - (i + 1)), 1.0 * (i + 1) * k);
        if (add < 0) continue;
        ans = max(ans, (a[i] + add) / (i + 1));
    }
    cout << setprecision(15) << fixed;

    cout << ans;
}
