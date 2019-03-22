#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<pair<int, int>> vals;
    vector<int> same_vals;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        vals.push_back({a[i], b[i]});
    }

    sort(vals.begin(), vals.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return (a.first + a.second) > (b.first + b.second);
    });

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2) ans -= vals[i].second;
        else ans += vals[i].first;
    }

    cout << ans;

}