#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const long long INF = 1LL << 62;

struct Edge {
    int v;
    int w;
};

struct Path {
    int pen;
    long long depth;
    int idx;

    bool operator<(const Path &p) {
        return pen < p.pen || (pen == p.pen && depth > p.depth);
    }

    double GetX(Path& p) {
        return (double)(depth - p.depth) / (p.pen - pen);
    }

    long long GetCost(Path& p) {
        return (long long)pen * p.pen + depth + p.depth;
    }
};

int n;
int penalty[MAXN];
int parents[MAXN];
int subtree_size[MAXN];
bool blocked[MAXN];
long long min_cost[MAXN];
vector<Edge> adj[MAXN];
vector<Path> paths;

void CalculateSubtreeSizes(int i, int p) {
    parents[i] = p;
    subtree_size[i] = 1;
    for (Edge &e : adj[i]) {
        if (e.v == p || blocked[e.v]) continue;
        CalculateSubtreeSizes(e.v, i);
        subtree_size[i] += subtree_size[e.v];
    }
}

void FindPaths(int i, int p, long long depth) {
    paths.push_back({penalty[i], depth, i});
    for (Edge &e : adj[i]) {
        if (blocked[e.v] || e.v == p) continue;
        FindPaths(e.v, i, depth + e.w);
    }
}

void GetMinCost(int centroid) {

    paths = vector<Path>();
    paths.push_back({penalty[centroid], 0, centroid});
    for (Edge &e : adj[centroid]) {
        if (!blocked[e.v]) {
            FindPaths(e.v, centroid, e.w);
        }
    }

    sort(paths.begin(), paths.end());

    vector<Path> considered_paths;
    for (int i = paths.size() - 1; i >= 0; i--) {
        while (considered_paths.size() > 1 && considered_paths[considered_paths.size() - 2].GetX(considered_paths.back()) >= considered_paths.back().GetX(paths[i])) {
            considered_paths.pop_back();
        }

        considered_paths.push_back(paths[i]);
        while (i > 0 && paths[i].pen == paths[i - 1].pen) i--;
    }

    int idx = 0;
    for (int i = 0; i < paths.size(); i++) {
        while (idx < considered_paths.size() - 1 && paths[i].GetCost(considered_paths[idx]) >= paths[i].GetCost(considered_paths[idx + 1])) {
            idx++;
        }
        min_cost[paths[i].idx] = min(min_cost[paths[i].idx], paths[i].GetCost(considered_paths[idx]));
    }

}

void Go(int entry_point) {
    CalculateSubtreeSizes(entry_point, entry_point);

    int centroid = entry_point;
    int best_size = subtree_size[entry_point];
    
    queue<int> q;
    q.push(entry_point);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int sz = subtree_size[entry_point] - subtree_size[cur];

        for (Edge &e : adj[cur]) {
            if (blocked[e.v] || e.v == parents[cur]) continue;
            
            sz = max(sz, subtree_size[e.v]);
            q.push(e.v);
        }

        if (sz < best_size) {
            best_size = sz;
            centroid = cur;
        }
    }

    GetMinCost(centroid);
    blocked[centroid] = true;
    for (Edge &e : adj[centroid]) {
        if (!blocked[e.v]) Go(e.v);
    }
}





int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> penalty[i];
    for (int i = 1; i <= n; i++) min_cost[i] = (long long)penalty[i] * penalty[i];


    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Go(1);

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += min_cost[i];
    }

    cout << ans;
}
