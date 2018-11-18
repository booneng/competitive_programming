#include <bits/stdc++.h>

using namespace std;

long long twop[51];

long long solve() {
  int n, p;
  cin >> n >> p;
  long long ans = twop[n];
  unordered_set<string> ss;
  for (int i = 0; i < p; i++) {
    string prefix;
    cin >> prefix;
    bool add = true;
    vector<string> erasures;
    for (string s : ss) {
      if (s.size() < prefix.size()) {
	if (prefix.substr(0, s.size()) == s) {
	  add = false;
	}
      }
      else if (s.size() > prefix.size()) {
	if (s.substr(0, prefix.size()) == prefix) {
	  erasures.push_back(s);
	}
      }
    }
    for (string s : erasures) {
      ss.erase(s);
    }
    if (add) ss.insert(prefix);
  }

  for (string s : ss) {  
    int k = s.size();
    ans -= twop[n - k];
  }
  return max(ans, 0LL);
}

int main() {
  long long mul = 2;
  twop[0] = 1;
  for (int i = 1; i <= 50; i++) {
    twop[i] = mul;
    mul *= 2;
  }
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": " << solve() << endl;
  }
}
