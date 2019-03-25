#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1000000007;

int n, k;
vector<int> adj[100005];
bool visited[100005];

int dfs(int u) {
    
    visited[u] = true;
    int sz = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            sz += dfs(v);
        }
    }
    return sz;
}

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int powmod(int a, int p) {
    int res = 1;

    while (p) {
        if (p & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        p >>= 1;
    }
    return res;
}

int main() {
    cin >> n >> k;

    memset(visited, false, (n + 1) * sizeof(bool));

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int comp = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int sz = dfs(i);
            comp += powmod(sz, k);
            if (comp >= mod) comp -= mod;
        }
    }

    int ans = powmod(n, k) - comp;
    if (ans < 0) ans += mod;
    cout << ans;

}