#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100005;
const int M = 100005;

vector<pair<int, int>> edges;
int a[N];
int parents[N];
long long weight[N];
bool included[M];
bool used[M];
int u[M], v[M], w[M];
vector<pair<int, int>> adj[N];

int find(int a) {
    if (parents[a] == a) return a;
    int pa = find(parents[a]);
    parents[a] = pa;
    return pa;
}

void join(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    parents[pb] = pa;
    weight[pa] += weight[pb];
}

void dfs(int i, int wi) {
    for (auto& p : adj[i]) {
        if (used[p.second]) continue;
        if (w[p.second] <= wi) {
            used[p.second] = true;
            dfs(p.first, wi);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        parents[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        ui--;
        vi--;
        edges.push_back({wi, i});
        w[i] = wi;
        u[i] = ui;
        v[i] = vi;
        adj[ui].push_back({vi, i});
        adj[vi].push_back({ui, i});
    }

    sort(edges.begin(), edges.end());
    memset(included, false, sizeof(included));

    for (int i = 0; i < m; i++) {
        int idx = edges[i].second;
        int wi = edges[i].first;
        int pu = find(u[idx]);
        int pv = find(v[idx]);
        if (pu != pv) {
            join(pu, pv);
        }
        if (weight[find(pu)] >= wi) {
            included[idx] = true;
        }
    }

    memset(used, false, sizeof(used));
    for (int i = m - 1; i >= 0; i--) {
        int idx = edges[i].second;
        int wi = edges[i].first;
        if (used[idx]) continue;
        if (included[idx]) {
            dfs(u[idx], wi);
        }
    }

    int ans = m;

    for (int i = 0; i < m; i++) {
        if (used[i]) ans--;
    }
    cout << ans;
}
