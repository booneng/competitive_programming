#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int add(int a, int b) {
  return (a + b) % mod;
}

int mul(int a, int b) {
  long long x = a;
  long long y = b;
  return (x * y) % mod;
}


int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int left = 0;
  int right = 0;
  vector<int> cnts(26, 0);
  for (char c : s) {
    cnts[c - 'a']++;
  }
  int pre = 0;
  while (s[pre] == s[0]) pre++;
  int post = n - 1;
  while (s[post] == s[n - 1]) post--;
  int ans = 1;

  ans = add(ans, pre - 0);
  ans = add(ans, n - 1 - post);
  if (s[0] == s[n - 1]) {
    ans = add(ans, mul(pre - 0, n - 1 - post));
  }
  cout << ans;
}
