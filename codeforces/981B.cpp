#include <iostream>
#include <map>

#define ll long long int

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> prices;
  for (int i = 0; i < n; i++) {
    int a, x;
    cin >> a >> x;
    prices[a] = x;
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int b, y;
    cin >> b >> y;
    prices[b] = max(prices[b], y);
  }

  ll ans = 0;
  for (auto &it : prices) {
    ans += it.second;
  }
  cout << ans;
}
