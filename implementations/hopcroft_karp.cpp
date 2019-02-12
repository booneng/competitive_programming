/* this algorithm is for maximum bipartite matching
in O(v^(1/2) * E) complexity which is better than
converting the problem to maximum flow and solve using
ford-fulkerson */
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

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
    Matching m(4, 4);
    m.addEdge(1, 2); 
    m.addEdge(1, 3); 
    m.addEdge(2, 1); 
    m.addEdge(3, 2); 
    m.addEdge(4, 2); 
    m.addEdge(4, 4);

    cout << m.hopcroftKarp() << endl;
}