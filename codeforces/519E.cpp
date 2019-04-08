#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 100005;
const int LOGN = 17;

int n, m;
vector<int> adj[N];
int subtree_size[N];
int parents[LOGN][N];
int depth[N];
int pre[N];
int post[N];

int timer = 0;

int dfs(int u, int p) {
    if (p > 0) depth[u] = depth[p] + 1;
    parents[0][u] = p;
    subtree_size[u] = 1;
    pre[u] = timer++;
    for (int v : adj[u]) {
        if (v == p) continue;
        subtree_size[u] += dfs(v, u);
    }
    post[u] = timer++;
    return subtree_size[u];
}

bool ancestor(int u, int v) {
    return pre[u] <= pre[v] && post[v] <= post[u];
}

int walk(int u, int k) {

    for (int d = 0; d < LOGN && k > 0; d++) {
        if (k & 1) {
            u = parents[d][u];
        }
        k >>= 1;
    }
    return u;
}

int lca(int u, int v) {
    if (ancestor(u, v)) return u;
    else if (ancestor(v, u)) return v;

    for (int d = LOGN - 1; d >= 0; d--) {
        if (parents[d][u] > 0 && !ancestor(parents[d][u], v)) {
            u = parents[d][u];
        }
    }

    return parents[0][u];
}

int query(int u, int v) {
    if (u == v) return n;
    if (depth[u] < depth[v]) swap(u, v);
    int l = lca(u, v);

    if (l == u || l == v) {
        int dist = depth[u] - depth[v];
        if (dist % 2) return 0;
        int mid = walk(u, dist / 2);
        int one_below = walk(u, dist / 2 - 1);
        int res = subtree_size[mid] - subtree_size[one_below];
        return res;
    }
    else {
        if (depth[u] == depth[v]) {
            int dist = depth[u] - depth[l];
            u = walk(u, dist - 1);
            v = walk(v, dist - 1);
            int res = n - subtree_size[u] - subtree_size[v];
            return res;
        }
        else {
            int dist = depth[u] + depth[v] - 2 * depth[l];
            if (dist % 2) return 0;
            int mid = walk(u, dist / 2);
            int one_below = walk(u, dist / 2 - 1);
            int res = subtree_size[mid] - subtree_size[one_below];
            return res;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        for (int d = 0; d < LOGN; d++) {
            parents[d][i] = -1;
        }
    }

    depth[1] = 0;
    dfs(1, -1);

    for (int d = 1; d < LOGN; d++) {
        for (int i = 1; i <= n; i++) {
            int mid = parents[d - 1][i];
            if (mid != -1) {
                parents[d][i] = parents[d - 1][mid];
            }
        }
    }

    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << endl;
    }

}