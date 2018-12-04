// this program finds the longest anagramatically equivalent substring of s1 and s2


#include <bits/stdc++.h>

using namespace std;

namespace std { 
  template<> struct hash<pair<int, int> > { 
    size_t operator() (const pair<int, int>& key) const {
      return hash<int>()(key.first) + hash<int>()(key.second);
    }
  };
}
  

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  string s1;
  string s2;
  cin >> s1 >> s2;
  if (s1.size() > s2.size()) swap(s1, s2);
  const vector<int> primes = {1000000007, 1000000009};
    
  int psize = primes.size();

  int n = 4001;
  vector<vector<int>> powers(psize, vector<int>(26));
  for (int i = 0; i < primes.size(); i++) {
    long long cur = 1;
    for (int j = 0; j < 26; j++) {
      powers[i][j] = cur;
      cur = (cur * n) % primes[i];
    }
  }
  vector<vector<int>> asums1(psize, vector<int>(s1.size() + 1, 0));
  vector<vector<int>> asums2(psize, vector<int>(s2.size() + 1, 0));
  for (int i = 0; i < primes.size(); i++) {
    for (int j = 0; j < s1.size(); j++) {
      asums1[i][j + 1] = (asums1[i][j] + powers[i][s1[j] - 'a']) % primes[i];
    }
    for (int j = 0; j < s2.size(); j++) {
      asums2[i][j + 1] = (asums2[i][j] + powers[i][s2[j] - 'a']) % primes[i];
    }
  }

  
  int ans = 0;
  for (int len = s1.size(); len >= 1; len--) {
    unordered_set<pair<int, int>> table;
    for (int i = 0; i <= s1.size() - len; i++) {
      int j = i + len;
      int hash1 = asums1[0][j] - asums1[0][i];
      int hash2 = asums1[1][j] - asums1[1][i];
      if (hash1 < 0) hash1 += primes[0];
      if (hash2 < 0) hash2 += primes[1];
      table.insert({hash1, hash2});
    }
    
    for (int i = 0; i <= s2.size() - len; i++) {
      int j = i + len;
      int hash1 = asums2[0][j] - asums2[0][i];
      int hash2 = asums2[1][j] - asums2[1][i];
      if (hash1 < 0) hash1 += primes[0];
      if (hash2 < 0) hash2 += primes[1];
      if (table.find({hash1, hash2}) != table.end()) {
	ans = len;
	break;
      }
    }
    if (ans) break;
  }
  cout << ans << endl;
}
