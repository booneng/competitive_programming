#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int count_w[n], count_e[n];
  count_w[0] = 0;
  count_e[n - 1] = 0;
  if (s[0] == 'W') count_w[0]++;
  if (s[n - 1] == 'E') count_e[n - 1]++;
  for (int i = 1; i < n; i++) {
    count_w[i] = count_w[i - 1];
    if (s[i] == 'W') count_w[i]++;
  }

  for (int i = n - 2; i >= 0; i--) {
    count_e[i] = count_e[i + 1];
    if (s[i] == 'E') count_e[i]++;
  }

  int ans = min(count_e[1], count_w[n - 2]);
  for (int i = 1; i < n - 1; i++) {
    ans = min(ans, count_w[i - 1] + count_e[i + 1]); 
  }

  cout << ans;

}
