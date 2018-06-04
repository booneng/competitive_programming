#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int
using namespace std;

void solve() {
  int n, l;
  int c[100005];
  cin >> n >> l;
  int total = 0;
  for (int i = 0; i < l; i++) {
    cin >> c[i];
    total += c[i];
  }
  
  vector<double> decimals;
  int percentage = 0;
  double single = 100.0 / n;
  int sf = 100 / n;
  double rem = single - sf;
  
  for (int i = 0; i < l; i++) {
    double cur = c[i] * single;
    int floor = cur;
    int add;
    if (cur - floor < 0.5) {
      decimals.push_back(cur - floor);
      add = floor;
    }
    else {
      add = floor + 1;
    }
    percentage += add;
  }

  if (rem >= 0.5) {
    percentage += (n - total) * (sf + 1);
    cout << percentage << endl;
    return;
  }

  if (rem == 0.0) {
    cout << 100 << endl;
    return;
  }
  
  sort(decimals.begin(), decimals.end(), greater<double>());
  int left = n - total;
  for (int i = 0; i < decimals.size(); i++) {
    double have = decimals[i];
    int count = 0;
    while (have < 0.5) {
      have += rem;
      count++;
    }
    if (count <= left) {
      left -= count;
      percentage += count * sf + 1;
    }
    else {
      break;
    }
  }
  int point5 = int(0.5 / rem);
  if (point5 * rem < 0.5) point5++;
  percentage += left * sf;
  percentage += left / point5;
  cout << percentage << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
