#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

const int MAXN = 100005;

struct Edge {
    int v;
    int w;
};

struct Path {
    int w;
    bool t;
};

vector<Edge> adj[MAXN];
bool blocked[MAXN];
int subtree_size[MAXN];
int parent[MAXN];
int path_sat[2 * MAXN];
int path_unsat[2 * MAXN];
int depth_seen[2 * MAXN];
vector<Path> paths;

int n;
int offset;

void CalculateSubtreeSizes(int i, int p) {
    parent[i] = p;
    subtree_size[i] = 1;

    for (Edge &e : adj[i]) {
        if (e.v != p && !blocked[e.v]) {
            CalculateSubtreeSizes(e.v, i);
            subtree_size[i] += subtree_size[e.v];
        }
    }
}

void FindPaths(int i, int p, int sum) {
    paths.push_back({sum, depth_seen[sum + offset] > 0});
    depth_seen[sum + offset]++;

    for (Edge &e : adj[i]) {
        if (e.v != p && !blocked[e.v]) {
            FindPaths(e.v, i, sum + e.w);
        }
    }
    
    depth_seen[sum + offset]--;
}


long long SolveTree(int root, int comp_size) {

    for (int i = offset - comp_size + 1; i <= offset + comp_size - 1; i++) {
        path_sat[i] = 0;
        path_unsat[i] = 0;
    }

    long long res = 0;

    for (Edge &e : adj[root]) {
        if (blocked[e.v]) continue;

        paths = vector<Path>();
        FindPaths(e.v, root, e.w);

        for (Path &p : paths) {
            if (p.t || p.w == 0) {
                res += path_unsat[offset - p.w];
            }
            res += path_sat[offset - p.w];

            if (p.w == 0 && p.t) {
                res++;
            }
        }

        for (Path &p : paths) {
            if (p.t)
                path_sat[p.w + offset]++;
            else
                path_unsat[p.w + offset]++;
        }
    }
    
    return res;
    
}

long long Go(int entry_point) {
    CalculateSubtreeSizes(entry_point, entry_point);

    int centroid = entry_point;
    int best_size = subtree_size[entry_point];

    
    int comp_size = 0;
    queue<int> q;
    q.push(entry_point);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        comp_size++;
        int sz = subtree_size[entry_point] - subtree_size[cur];

        for (Edge &e : adj[cur]) {
            if (e.v != parent[cur] && !blocked[e.v]) {
                sz = max(sz, subtree_size[e.v]);
                q.push(e.v);
            }
        }

        if (sz < best_size) {
            best_size = sz;
            centroid = cur;
        }
    }
    

    long long ways = SolveTree(centroid, comp_size);
    blocked[centroid] = true;
    for (Edge &e : adj[centroid]) {
        if (!blocked[e.v]) {
            ways += Go(e.v);
        }
    }

    return ways;
}

int main() {
    ifstream cin("yinyang.in");
    ofstream cout("yinyang.out");
    cin >> n;
    offset = n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        w = 2 * w - 1;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(blocked, false, sizeof(blocked));
    cout << Go(1);
}