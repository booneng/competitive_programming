#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

string flows[155];
string req[155];

int count_flows[45] = {0};
int count_req[45] = {0};

void solve() {
  int n, l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> flows[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> req[i];
  }
  int ans = 0;
  
  // unordered_set<string> reqs;
  set<string> reqs;
  for (int i = 0; i < n; i++) reqs.insert(req[i]);
  
  // unordered_set<string> flip_strings;
  set<string> flip_strings;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      string s1 = flows[i];
      string s2 = req[j];
      string fs;
      int score = 0;
      for (int k = 0; k < l; k++) {
	if (s1[k] != s2[k]) fs += '1', score++;
	else fs += '0';
      }
      flip_strings.insert(fs);
    }
  }

  int min_score = 1000;
  for (set<string>::iterator it = flip_strings.begin(); it != flip_strings.end(); it++) {
    string fs = *it;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      string check;
      for (int j = 0; j < l; j++) {
	char add = flows[i][j];
	if (fs[j] == '1') {
	  add = (add == '1') ? '0' : '1';
	}
	check += add;
      }
      if (reqs.find(check) == reqs.end()) {
	ok = false;
	break;
      }
      if (!ok) break;
    }
    if (ok) {
      int score = 0;
      for (int i = 0; i < l; i++) {
	if (fs[i] == '1') score++;
      }
      min_score = min(min_score, score);
    }
  }
  if (min_score == 1000) cout << "NOT POSSIBLE" << endl;
  else cout << min_score << endl;
}


int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
