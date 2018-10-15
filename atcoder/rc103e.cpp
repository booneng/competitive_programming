#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if (s[0] == '0' || s[n - 1] == '1') {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 2 - i]) {
      cout << -1;
      return 0;
    }
  }

  queue<int> zeros;
  vector<int> ones;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') zeros.push(i + 1);
    else ones.push_back(i + 1);
  }

  int prev = 1;
  for (int i = 1; i < ones.size(); i++) {
    cout << ones[i - 1] << ' ' << ones[i] << endl;
  }
  cout << ones[ones.size() - 1] << ' ' << n << endl;

  for (int i = 1; i < ones.size(); i++) {
    int feet = ones[i] - ones[i - 1] - 1;
    for (int j = 0; j < feet; j++) {
      cout << ones[i] << ' ' << zeros.front() << endl;
      zeros.pop();
    }
  }
  
}
