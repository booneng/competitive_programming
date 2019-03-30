/* tags: binary lifting, trees */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 200005;
const int LOGN = 20;

int n;
vector<int> adj[N];
int parents[LOGN][N];
int depth[N];

int walk(int u, int k) {
    for (int d = 0; d < LOGN && u != -1; d++) {
        if (k & 1) {
            u = parents[d][u];
        }
        k >>= 1;
    }
    return u;
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) {
        u = walk(u, depth[u] - depth[v]);
    }
    else if (depth[v] > depth[u]) {
        v = walk(v, depth[v] - depth[u]);
    }
    if (u == v) return u;

    for (int d = LOGN - 1; d >= 0; d--) {
        if (parents[d][u] != parents[d][v]) {
            u = parents[d][u];
            v = parents[d][v];
        }
    }

    return parents[0][u];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}


int main() {
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

    queue<int> q;
    vector<bool> seen(n + 1);
    q.push(1);
    parents[0][1] = -1;
    depth[1] = 0;
    seen[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int v : adj[cur]) {
            if (!seen[v]) {
                parents[0][v] = cur;
                depth[v] = depth[cur] + 1;
                seen[v] = true;
                q.push(v);
            }
        }
    }

    for (int d = 1; d < LOGN; d++) {
        for (int i = 1; i <= n; i++) {
            int mid = parents[d - 1][i];
            if (mid != -1) {
                parents[d][i] = parents[d - 1][mid];
            }
        }
    }

    long long res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            res += dist(i, j) + 1;
        }
    }

    cout << res;
}