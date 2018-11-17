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
  for (int i = 1; i <= cnts[cnts.size() - 1]; i++) {
    int sum = 0;
    int mul = i;
    auto it = lower_bound(cnts.begin(), cnts.end(), mul);
    while (it != cnts.end()) {
      sum += mul;
      mul *= 2;
      it = lower_bound(it + 1, cnts.end(), mul);
    }
    ans = max(ans, sum);
    
  }
  cout << ans;
}
