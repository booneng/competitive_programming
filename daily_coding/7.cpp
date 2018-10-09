#include <iostream>

using namespace std;

void decode(string s) {
  int n = s.size();
  int dp[n + 1];
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
      dp[i + 1] = dp[i] + dp[i - 1];
    }
    else {
      dp[i + 1] = dp[i];
    }
  }
  cout << dp[n];
}

int main() {
  string s;
  cin >> s;
  decode(s);
}
