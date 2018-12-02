#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> diags1(2001, 0);
  vector<int> diags2(2001, 0);
  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    diags1[r - c + 1000]++;
    diags2[r + c]++;
  }

  int ans = 0;
  for (int i = 0; i < 2001; i++) {
    ans += (diags1[i] * (diags1[i] - 1)) / 2;
    ans += (diags2[i] * (diags2[i] - 1)) / 2;
  }
  cout << ans;
}
