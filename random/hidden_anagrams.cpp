#include <bits/stdc++.h>

using namespace std;



int main() {
  string s1;
  string s2;
  cin >> s1 >> s2;
  const vector<int> primes = {179426003, 179426453,
			      179425019, 179425559, 179426029, 179426491,
			      179425027, 179425579, 179426081, 179426549};
    
  int psize = primes.size();
  vector<bitset<180000000>> table(psize);

  int n = 4001;
  vector<vector<int>> powers(psize, vector<int>(26));
  for (int i = 0; i < primes.size(); i++) {
    long long cur = 1;
    for (int j = 0; j < 26; j++) {
      powers[i][j] = cur;
      cur = (cur * n) % primes[i];
    }
  }
  vector<vector<int>> asums1(psize, vector<int>(s1.size() + 1));
  vector<vector<int>> asums2(psize, vector<int>(s2.size() + 1));
  for (int i = 0; i < primes.size(); i++) {
    for (int j = 0; j < s1.size(); j++) {
      asums1[i][j + 1] = (asums1[i][j] + powers[i][s1[j] - 'a']) % primes[i];
    }
    for (int j = 0; j < s2.size(); j++) {
      asums2[i][j + 1] = (asums2[i][j] + powers[i][s2[j] - 'a']) % primes[i];
    }
  }
  for (int i = 0; i < s1.size(); i++) {
    for (int j = i; j < s1.size(); j++) {
      for (int k = 0; k < psize; k++) {
  	long long hash = asums1[k][j + 1] - asums1[k][i];
  	if (hash < 0) hash += primes[k];
  	table[k].set(hash);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < s2.size(); i++) {
    for (int j = i; j < s2.size(); j++) {
      int len = j + 1 - i;
      if (len <= ans) continue;
      bool contains = true;
      for (int k = 0; k < psize; k++) {
  	long long hash = asums2[k][j + 1] - asums2[k][i];
  	if (hash < 0) hash += primes[k];
  	if (!table[k][hash]) {
  	  contains = false;
  	  break;
  	}
      }
      if (contains) ans = len;
    }
  }
  cout << ans << endl;
}
