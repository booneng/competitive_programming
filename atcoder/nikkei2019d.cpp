#include <vector>
#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

const int N = 100005;

vector<int> adj[N];
vector<int> r_adj[N];
int parents[N];
vector<int> order;
bool visited[N];
int number;
int po_numbers[N];

void dfs(int i) {
    visited[i] = true;
    for (int v : adj[i]) {
        if (!visited[v])
            dfs(v);
    }
    po_numbers[i] = number++;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1 + m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        r_adj[v].push_back(u);
    }
    memset(visited, false, (n + 1) * sizeof(bool));
    number = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    for (int i = 1; i <= n; i++) {
        int min_po = INT_MAX;
        int parent = 0;
        for (int p : r_adj[i]) {
            if (po_numbers[p] < min_po) {
                min_po = po_numbers[p];
                parent = p;
            }
        }
        parents[i] = parent;
    }

    for (int i = 1; i <= n; i++) cout << parents[i] << endl;
}