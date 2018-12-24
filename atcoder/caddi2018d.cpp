#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  bool first = false;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    if (a % 2) first = true;
  }
  if (first) cout << "first";
  else cout << "second";
}