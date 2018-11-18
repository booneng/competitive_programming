#include <bits/stdc++.h>

using namespace std;

bool check(const int times, const int k, const unordered_map<int, int>& cnts) {
  vector<int> t;
  for (auto it = cnts.begin(); it != cnts.end(); it++) {
    if (it->second >= times) {
      int rep = it->second / times;
      for (int j = 0; j < rep; j++) {
	t.push_back(it->first);
	if (t.size() == k) break;
      }
    }
    if (t.size() == k) break;
  }
  return t.size() == k;
}


int main() {
  int n, k;
  cin >> n >> k;
  vector<int> s(n);
  unordered_map<int, int> cnts;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    cnts[s[i]]++;
  }

  int left = 1;
  int right = n / k;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (check(mid, k, cnts)) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  
  vector<int> t;
  for (auto it = cnts.begin(); it != cnts.end(); it++) {
    if (it->second >= right) {
      int rep = it->second / right;
      for (int j = 0; j < rep; j++) {
	t.push_back(it->first);
	if (t.size() == k) break;
      }
    }
    if (t.size() == k) break;
  }
  for (int i : t) cout << i << ' ';
}
