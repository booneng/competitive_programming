#include <bits/stdc++.h>

using namespace std;

int a[200005];
vector<int> adj[200005];
vector<int> primes[200005];
map<int, pair<int, int>> dp[200005];
int prime;

int check(int i, int parent) {
  if ((a[i] % prime) != 0) {
    return 0;
  }
  if (dp[i].find(prime) != dp[i].end()) {
    int max1 = dp[i][prime].first;
    int max2 = dp[i][prime].second;
    return (i == parent) ? (max1 + max2 + 1) : (max1 + 1);
  }
  int max1 = 0;
  int max2 = 0;
  for (int child : adj[i]) {
    if (child == parent) continue;
    int cur = check(child, i);
    if (cur > max1) {
      max2 = max1;
      max1 = cur;
    }
    else if (cur > max2) {
      max2 = cur;
    }
  }
  dp[i][prime] = {max1, max2};
  return (i == parent) ? (max1 + max2 + 1) : (max1 + 1);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for (int i = 0; i < n; i++) {
    int tmp = a[i];
    for (int p = 2; p * p <= tmp; p++) {
      if (tmp % p == 0) {
        primes[i].push_back(p);
        while (tmp % p == 0)
          tmp /= p;
      }
    }
    if (tmp > 1) {
      primes[i].push_back(tmp);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int p : primes[i]) {
      prime = p;
      ans = max(ans, check(i, i));
    }
  }
  cout << ans;
}