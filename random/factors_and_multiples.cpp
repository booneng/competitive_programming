// maximum bipartite matching problem
// http://lightoj.com/volume_showproblem.php?problem=1149

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

class Matching {

private:
    int n, m;
    vector<vector<int>> adj;
    vector<int> match;
    vector<int> dist;

public:
    Matching(int n, int m)
        : n(n),
        m(m),
        adj(n + m + 1),
        match(n + m + 1),
        dist(n + m + 1)
    {
    }

    bool bfs() {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (match[i] == 0) {
                dist[i] = 0;
                q.push(i);
            }
            else {
                dist[i] = INF;
            }
        }

        dist[0] = INF;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dist[match[v]] == INF) {
                    dist[match[v]] = dist[u] + 1;
                    q.push(match[v]);
                }
            }
        }
        return (dist[0] != INF);
    }

    bool dfs(int u) {
        if (u == 0) return true;
        for (int v : adj[u]) {
            if (dist[match[v]] == dist[u] + 1) {
                if (dfs(match[v])) {
                    match[u] = v;
                    match[v] = u;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v + n);
    }

    int hopcroftKarp() {
        int matching = 0;
        while (bfs()) {
            for (int i = 1; i <= n; i++) {
                if (match[i] == 0 && dfs(i)) {
                    matching++;
                }
            }
        }
        return matching;
    }
};


int main() {
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        Matching mat(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[j] % a[i] == 0) {
                    mat.addEdge(i + 1, j + 1);
                }
            }
        }
        cout << "Case " << c << ": " << mat.hopcroftKarp() << endl;
    }
}

