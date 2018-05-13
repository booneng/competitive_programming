#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int a[200005];
map<int, int> dp;

int main() {
  int n;
  cin >> n;
  int max_length = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  int max_num = a[0];
  dp[a[0]] = 1;
  for (int i = 1; i < n; i++) {
    dp[a[i]] = dp[a[i] - 1] + 1;
    if (dp[a[i]] > max_length) {
      max_length = max(dp[a[i]], max_length);
      max_num = a[i];
    }
  }
  cout << max_length << endl;
  max_length--;
  for (int i = 0; i < n; i++) {
    if (a[i] == max_num - max_length) {
      cout << i + 1 << ' ';
      max_length--;
      if (max_length < 0) break; 
    }
  }
}
