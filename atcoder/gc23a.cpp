#include <iostream>
#include <set>
#include <map>

#define ll long long int
using namespace std;

int main() {
  int n;
  cin >> n;
  ll a[200005];
  ll sums[200005];
  map<ll, int> seen;
  cin >> a[0];
  sums[0] = a[0];
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    sums[i] = sums[i - 1] + a[i];
  }
  seen[0] = 1;
  ll count = 0;
  for (int i = 0; i < n; i++) {
    count += seen[sums[i]];
    seen[sums[i]]++;
  }
  cout << count;
}
