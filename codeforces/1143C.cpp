#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int parents[N];
int respects[N];
bool deletable[N];
int n;


int main() {
    cin >> n;
    memset(deletable, true, sizeof(deletable));
    int root;
    for (int i = 1; i <= n; i++) {
        cin >> parents[i] >> respects[i];
        if (parents[i] == -1) root = i;
    }

    deletable[root] = false;
    for (int i = 1; i <= n; i++) {
        if (i == root) continue;
        if (!respects[i]) {
            deletable[parents[i]] = false;
            deletable[i] = false;
        }

    }

    bool can = false;
    for (int i = 1; i <= n; i++) {
        if (deletable[i]) {
            cout << i << ' ';
            can = true;
        }
    }
    if (!can) cout << -1;
}