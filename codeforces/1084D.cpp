#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

int n;
long long w[300005];
vector<pair<int, int>> adj[300005];
bool visited[300005];
long long dp[300005];

long long dfs(int u, int l) {
    visited[u] = true;
    long long m1 = 0, m2 = 0;
    for (auto p : adj[u]) {
        int v = p.first;
        int d = p.second;
        if (visited[v]) continue;
        long long cur = dfs(v, d);
        if (cur > m1) {
            m2 = m1;
            m1 = cur;
        }
        else if (cur > m2) {
            m2 = cur;
        }
    }
    dp[u] = w[u] + m1 + m2;
    return w[u] + m1 - l;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    memset(visited, false, sizeof(visited));
    for (int i = 1; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }


    dfs(1, 0);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

}
