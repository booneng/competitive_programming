#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 500;

int n;
vector<int> adj[MAXN];
bool blocked[MAXN];
int subtree_size[MAXN];
int parents[MAXN];

void CalculateSubtreeSizes(int i, int p) {
    parents[i] = p;
    subtree_size[i] = 1;

    for (int j : adj[i]) {
        if (parents[i] != j && !blocked[MAXN]) {
            CalculateSubtreeSizes(j, i);
            subtree_size[i] += subtree_size[j];
        }
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

        for (int j : adj[cur]) {
            if (j != parents[cur] && !blocked[j]) {
                sz = max(sz, subtree_size[j]);
                q.push(j);
            }
        }

        if (sz < best_size) {
            best_size = sz;
            centroid = cur;
        }
    }

    cout << centroid << endl;
    blocked[centroid] = true;
    for (int j : adj[entry_point]) {
        if (!blocked[j]) Go(j);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Go(0);
}