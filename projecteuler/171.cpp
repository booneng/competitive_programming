#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int multiply(int a, int b) {
  long long x = a;
  long long y = b;
  return (x * y) % MOD;
}

int addition(int a, int b) {
  return (a + b) % MOD;
}

int main() {
  string s;
  cin >> s;
  int ndigits = s.size();
  int max_sq = 81 * ndigits;
  vector<vector<int>> dpsum(ndigits, vector<int>(max_sq + 1, 0));
  vector<vector<int>> dpcnt(ndigits, vector<int>(max_sq + 1, 0));
  dpcnt[0][0] = 1;

  vector<int> powers(ndigits, 1);
  for (int i = 1; i < ndigits; i++) {
    powers[i] = multiply(powers[i - 1], 10);
  }
  for (int i = 1; i < ndigits; i++) {
    for (int j = 0; j < 10; j++) {
      int l = 0;
      int sqsum = j * j + l;
      while (sqsum <= max_sq) {
        int add = addition(dpsum[i - 1][l], multiply(dpcnt[i - 1][l], multiply(j, powers[i - 1])));
        dpsum[i][sqsum] = addition(dpsum[i][sqsum], add);
        dpcnt[i][sqsum] = addition(dpcnt[i][sqsum], dpcnt[i - 1][l]);
        l++;
        sqsum = j * j + l;
      }
    }
  }

  int check = 0;
  for (char c : s) {
    int m = c - '0';
    check += m * m;
  }

  int i = 1;
  int ans = 0;
  while (i * i <= max_sq) {
    if (i * i == check) {
      for (int p = s.size() - 1; p >= 0; p--) {
        int c = s[p] - '0';
        
        c = multiply(c, powers[s.size() - 1 - p]);
        ans = addition(ans, c);
      }
    }
    int cur_n = ndigits;
    int cur_sum = i * i;
    int mul = 0;
    int add = 0;
    for (int di = 0; di < s.size(); di++) {
      int c = s[di] - '0';
      for (int pre = 0; pre < c; pre++) {
        int prev = cur_sum - pre * pre;
        if (prev < 0) break;
        int tmul = mul + multiply(pre, powers[cur_n - 1]);
        add = addition(add, addition(dpsum[cur_n - 1][prev], multiply(tmul, dpcnt[cur_n - 1][prev])));
      }
      mul = addition(mul, multiply(c, powers[cur_n - 1]));
      cur_n--;
      cur_sum -= c * c;
      if (cur_sum < 0) break;
    }
    ans = addition(ans, add);
    i++;
  }
  cout << ans;
}
