#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  map<int, int> vcnts;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    vcnts[num]++;
  }
  vector<int> cnts;
  for (auto it = vcnts.begin(); it != vcnts.end(); it++) {
    cnts.push_back(it->second);
  }

  sort(cnts.begin(), cnts.end());
  int ans = 0;
  for (int i = 1; i <= cnts.back(); i++) {
    int pos = cnts.size() - 1;
    int cur = i;
    int res = cur;
    while (pos > 0 && cur % 2 == 0) {
      cur /= 2;
      pos--;
      if (cnts[pos] < cur) break;
      res += cur;
    }
    ans = max(ans, res);
  }
  cout << ans;
}
