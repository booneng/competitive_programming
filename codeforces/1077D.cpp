#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  unordered_map<int, int> cnts;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    cnts[s[i]]++;
  }

  map<int, int> cntcnts;
  for (auto it = cnts.begin(); it != cnts.end(); it++) {
    cntcnts[it->second]++;
  }

  int bound = 0;
  int maxtimes = 0;
  for (auto it = cntcnts.begin(); it != cntcnts.end(); it++) {
    int erasable = min(it->first, n / k);

    if (erasable < maxtimes) break;
    maxtimes = erasable;
    n -= it->second * it->first;
    bound = it->first;
  }

  vector<int> t;
  for (auto it = cnts.begin(); it != cnts.end(); it++) {
    if (it->second >= bound) {
      int times = it->second / maxtimes;
      for (int j = 0; j < times; j++) {
	t.push_back(it->first);
	if (t.size() == k) break;
      }
    }
    if (t.size() == k) break;
  }
  for (int i : t) cout << i << ' ';
}
