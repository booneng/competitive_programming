#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int N = 100005;
int a[N];
long long c[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    vector<pair<int, int>> costs;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        costs.push_back({c[i], i});
    }

    sort(costs.begin(), costs.end());
    int cost_index = 0;
    string ans;
    for (int i = 0; i < m; i++) {
        int t, d;
        cin >> t >> d;
        t--;
        long long cost = 0;
        while (d > 0 && cost_index < n) {
            if (a[t] > 0) {
                int use = min(d, a[t]);
                a[t] -= use;
                d -= use;
                cost += use * c[t];
            }
            else {
                int index = costs[cost_index].second;
                int use = min(d, a[index]);
                a[index] -= use;
                d -= use;
                cost += use * c[index];
                if (a[index]== 0) cost_index++;
            }
        }
        if (d > 0) cost = 0;
        ans += to_string(cost) + '\n';
    }
    cout << ans;
}