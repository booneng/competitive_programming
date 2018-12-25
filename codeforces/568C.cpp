#include <bits/stdc++.h>

using namespace std;


vector<int> adj[405];
vector<int> radj[405];
bool visited[405];
vector<int> order;
int ccs[405];
int assignments[405];
int cc;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
int n;

void dfs1(int i) {
  visited[i] = true;
  for (int v : radj[i]) {
    if (!visited[v]) dfs1(v);
  }
  order.push_back(i);
}

void dfs2(int i, const int cc) {
  ccs[i] = cc;
  visited[i] = true;
  for (int v : adj[i]) {
    if (!visited[v]) {
      dfs2(v, cc);
    }
  }
}

bool dfs_check(int i) {
  visited[i] = true;
  if (assignments[i] == 2) return false;
  assignments[i] = 1;
  assignments[(n + i) % (2 * n)] = 2;
  for (int v : adj[i]) {
    if (!visited[v] && !dfs_check(v)) return false;
  }
  return true;
}

bool check() {
  fill(visited, visited + 2 * n, false);
  for (int i = 0; i < 2 * n; i++) {
    if (!visited[i] && assignments[i] == 1) {
      if (!dfs_check(i)) return false;
    }
  }
  return true;
}


int main() {
  string types;
  cin >> types;
  bool no_c = true;
  bool no_v = true;
  for (char c : types) {
    if (c == 'V') no_v = false;
    else no_c = false;
  }
  int l = (int)types.size();

  int m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int p1, p2;
    string t1, t2;
    cin >> p1 >> t1 >> p2 >> t2;
    p1--;
    p2--;
    if (t1 == "C") p1 += n;
    if (t2 == "C") p2 += n;
    int np1 = (p1 + n) % (2 * n);
    int np2 = (p2 + n) % (2 * n);
    adj[p1].push_back(p2);
    adj[np2].push_back(np1);

    radj[p2].push_back(p1);
    radj[np1].push_back(np2);
  }

  fill(visited, visited + 2 * n, false);

  for (int i = 0; i < 2 * n; i++) {
    if (!visited[i]) dfs1(i);
  }
  reverse(order.begin(), order.end());
  fill(visited, visited + 2 * n, false);

  cc = 0;
  for (int i : order) {
    if (!visited[i]) dfs2(i, cc++);
  }

  for (int i = 0; i < n; i++) {
    if (ccs[i] == ccs[n + i]) {
      cout << -1;
      return 0;
    }
  }

  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int num = s[i] - 'a';
    if (types[num] == 'V') {
      assignments[i] = 1;
      assignments[i + n] = 2;
    }
    else {
      assignments[i] = 2;
      assignments[i + n] = 1;
    }
  }

  if (check()) {
    cout << s;
    return 0;
  }
  int first_v = l;
  int first_c = l;
  for (int i = 0; i < l; i++) {
    if (types[i] == 'V') first_v = min(i, first_v);
    else first_c = min(i, first_c);
  }


  for (int i = n - 1; i >= 0; i--) {
    int c = s[i] - 'a';
    int next_c = c + 1;
    for (int j = 0; j < 2 && next_c < l; j++) {

      s[i] = alphabet[next_c];
      
      if (types[next_c] == 'V') {
        assignments[i] = 1;
        assignments[i + n] = 2;
      }
      else {
        assignments[i] = 2;
        assignments[i + n] = 1;
      }

      if (check()) {
        s[i] = alphabet[next_c];
        fill(visited, visited + 2 * n, false);
        for (int k = i + 1; k < n; k++) {
          if (assignments[k] == 0) {
            if (first_v < first_c) {
              dfs_check(k);
            }
            else {
              dfs_check(k + n);
            }
          }
          if (assignments[k] == 1) {
            if (no_v) {
              cout << -1;
              return 0;
            }
            s[k] = alphabet[first_v];
          }
          else if (assignments[k] == 2) {
            if (no_c) {
              cout << -1;
              return 0;
            }
            s[k] = alphabet[first_c];
          }

        }

        cout << s;
        return 0;
      }
      for (int k = i; k < n; k++) {
        assignments[k] = 0;
        assignments[k + n] = 0;
      }
      while (next_c < l && types[next_c] == types[c + 1]) next_c++;
    }
    for (int k = i; k < n; k++) {
      assignments[k] = 0;
      assignments[k + n] = 0;
    }
  }
  cout << -1;
}