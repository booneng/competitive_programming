#include <bits/stdc++.h>

using namespace std;

vector<set<int>> groups;
map<string, int> names;
long long graph[50];
map<long long, int> dp;

int solve(long long mask) {
  if (dp.find(mask) != dp.end()) {
    return dp[mask];
  }

  int s = __builtin_ctzll(mask);
  dp[mask] = max(solve(mask ^ (1LL << s)), 1 + solve(mask & graph[s]));
  return dp[mask];
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0, index = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      groups.push_back({});
    }
    else {
      string s;
      cin >> s;
      if (names.find(s) == names.end()) {
        names[s] = index++;
      }
      groups.back().insert(names[s]);
    }
  }

  for (int i = 0; i < m; i++) {
    graph[i] = ((1LL << m) - 1) ^ (1LL << i);
  }

  for (auto s : groups) {
    for (int i : s) {
      for (int j : s) {
        graph[i] &= ~(1LL << j);
      }
    }
  }
  dp[0] = 0;
  cout << solve((1LL << m) - 1);
}