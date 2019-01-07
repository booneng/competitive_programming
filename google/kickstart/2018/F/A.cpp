#include <bits/stdc++.h>

using namespace std;

int solve() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  vector<vector<int>> cnt1(n + 1, vector<int>(26, 0));
  vector<vector<int>> cnt2(n + 1, vector<int>(26, 0));
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < 26; k++) {
      cnt1[i][k] = cnt1[i - 1][k];
      cnt2[i][k] = cnt2[i - 1][k];
    }
    cnt1[i][s1[i - 1] - 'A']++;
    cnt2[i][s2[i - 1] - 'A']++;
  }
  
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int len = j - i + 1;
      vector<int> subcnts(26);
      for (int k = 0; k < 26; k++) {
	subcnts[k] = cnt1[j][k] - cnt1[i - 1][k];
      }
      for (int left = 1; left <= n - len + 1; left++) {
	int right = left + len - 1;
	bool can = true;
	for (int k = 0; k < 26; k++) {
	  if (cnt2[right][k] - cnt2[left - 1][k] != subcnts[k]) {
	    can = false;
	    break;
	  }
	}
	if (can) {
	  ans++;
	  break;
	}
      }
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": " << solve() << endl;
  }
}
